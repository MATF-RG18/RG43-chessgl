#include "ObjectHandler.hpp"

ObjectHandler::ObjectHandler() {};

/* Funkcija otvara prosledjeni fajl */
void ObjectHandler::prepFile(char* niska){
    FILE * file = fopen(niska, "r");
    if(file == NULL) 
    {
        std::cerr << "LOS FAJL!" << std::endl;
        exit(EXIT_FAILURE);
    }

    this->file = file;
}

/* Iscrtavanje isparsiranog modela */
void ObjectHandler::draw(int x, int y, int z){

    glPushMatrix();

        glColor3f(0.2, 0.2, 0.2);
        glTranslatef(x, y, z);
        glBegin(GL_TRIANGLES);
            for(int i=0; i<model_size; i++){
                glNormal3f(model[i].normal[0], model[i].normal[1], model[i].normal[2]);
                glVertex3f(model[i].position[0], model[i].position[1], model[i].position[2]);
            } 
        glEnd();
                
    glPopMatrix();
}


/* Parsiranje modela iz .obj fajla u format spreman za crtanje*/
void ObjectHandler::loadModel(){

    int verts_count = 0;
    int verts_count_of = STEP;
    Vertex *verts = (Vertex*)malloc(verts_count_of * sizeof(Vertex));
    int num_of_pos = STEP;
    double **positions = (double**)malloc(num_of_pos * sizeof(double*));
    for(int i=0; i<num_of_pos; i++){
        positions[i] = (double*)malloc(3 * sizeof(double));
    }
    positions[0][0] = 0;
    positions[0][1] = 0;
    positions[0][2] = 0;

    int num_of_tc = STEP;
    double **texcoords = (double**)malloc(num_of_tc * sizeof(double*));
    for(int i=0; i<num_of_tc; i++){
        texcoords[i] = (double*)malloc(3*sizeof(double));
    }
    texcoords[0][0] = 0;
    texcoords[0][1] = 0;
    texcoords[0][2] = 0;

    int num_of_n = STEP;
    double **normals = (double**)malloc(num_of_n * sizeof(double*));
    for(int i=0; i<num_of_n; i++){
        normals[i] = (double*)malloc(3*sizeof(double));
    }
    normals[0][0] = 0;
    normals[0][1] = 0;
    normals[0][2] = 0;

    char *line = NULL;
    size_t len = 0;
    ssize_t read = 0;
    int countPos = 1;
    int countTC = 1;
    int countN = 1;
    while((read = getline(&line, &len, file)) != -1){
        char type[5];
        sscanf(line, "%s ", type);
        if(strcmp(type, "v") == 0){
            double x = 0, y = 0, z = 0;
            sscanf(line, "v %lf %lf %lf",   &x, &y, &z);
            if(countPos >= num_of_pos){
                num_of_pos += STEP;
                positions = (double**)realloc(positions, num_of_pos * sizeof(double*));
                for(int i=countPos; i<num_of_pos; i++)
                    positions[i] = (double*)malloc(3 * sizeof(double));
            }
            positions[countPos][0] = x;
            positions[countPos][1] = y;
            positions[countPos][2] = z;
            countPos += 1;
        }
        
        if(strcmp(type, "vt") == 0){
            double u = 0, v = 0, t = 0;
            sscanf(line, "vt %lf %lf %lf", &u, &v, &t);
            if(countTC >= num_of_tc){
                num_of_tc += STEP;
                texcoords = (double**)realloc(texcoords, num_of_tc * sizeof(double*));
                for(int i=countTC; i<num_of_tc; i++)
                    texcoords[i] = (double*)malloc(3*sizeof(double));
            }
            texcoords[countTC][0] = u;
            texcoords[countTC][1] = v;
            texcoords[countTC][2] = t;
            countTC += 1;
        }

        if(strcmp(type, "vn") == 0){
            double i = 0, j = 0, k = 0;
            sscanf(line, "vn %lf %lf %lf", &i, &j, &k);
            if(countN >= num_of_n){
                num_of_n += STEP;
                normals = (double**)realloc(normals, num_of_n * sizeof(double*));
                for(int i=countN; i<num_of_n; i++)
                    normals[i] = (double*)malloc(3*sizeof(double));
            }
            normals[countN][0] = i;
            normals[countN][1] = j;
            normals[countN][2] = k;
            countN += 1;
        }

        if(strcmp(type, "f") == 0){
            int ref_step = STEP;
            VertRef *refs = (VertRef*)malloc(ref_step * sizeof(VertRef));
            char a[256];
            char *newF = strchr(line, 'f') + 2;
            
            int offset = 0;
            int ref_count = 0;
            while(sscanf(newF, " %s%n", a, &offset) == 1){
                char *vta = strchr(a, '/')+1;
                char *vna = strchr(vta, '/')+1;
                a[strlen(a) - strlen(vta)-1] = '\0';
                if(vta[0] == '/'){
                    vta = "0";
                }
                
                newF += offset;
                if(ref_count >= ref_step){
                    ref_step += STEP;
                    refs = (VertRef*)realloc(refs, ref_step*sizeof(VertRef));
                }
                refs[ref_count].v = atoi(a);
                refs[ref_count].vn = atoi(vna);
                refs[ref_count].vt = atoi(vta);
                ref_count += 1;
            }
            for(int i=1; i+1 < ref_count; i++){
                const VertRef *p[3] = {&refs[0], &refs[i], &refs[i+1]};
                double U[3] ={0};
                U[0] = positions[ p[1]->v ][0] - positions[ p[0]->v ][0];
                U[1] = positions[ p[1]->v ][1] - positions[ p[0]->v ][1];
                U[2] = positions[ p[1]->v ][2] - positions[ p[0]->v ][2];
                double V[3] ={0};
                V[0] = positions[ p[2]->v ][0] - positions[ p[0]->v ][0];
                V[1] = positions[ p[2]->v ][1] - positions[ p[0]->v ][1];
                V[2] = positions[ p[2]->v ][2] - positions[ p[0]->v ][2];
                double N[3] = {0};

                N[0] = U[1]*V[2] - U[2]*V[1];
                N[1] = U[2]*V[0] - U[0]*V[2];
                N[2] = U[0]*V[1] - U[1]*V[0];

                double w = sqrt(N[0]*N[0] + N[1]*N[1] + N[2]*N[2]);
                N[0] /= w;
                N[1] /= w;
                N[2] /= w;
                for(int j=0; j<3; j++){
                    Vertex vert;

                    vert.position[0] = positions[ p[j]->v ][0];
                    vert.position[1] = positions[ p[j]->v ][1];
                    vert.position[2] = positions[ p[j]->v ][2];

                    vert.texcoord[0] = texcoords[ p[j]->vt ][0];
                    vert.texcoord[1] = texcoords[ p[j]->vt ][1];
                    if(p[j]->vn != 0){
                        vert.normal[0] = normals[ p[j]->vn ][0];
                        vert.normal[1] = normals[ p[j]->vn ][1];
                        vert.normal[2] = normals[ p[j]->vn ][2];
                    } else {
                        vert.normal[0] = N[0];
                        vert.normal[1] = N[1];
                        vert.normal[2] = N[2];
                    }
                    if(verts_count >= verts_count_of){
                        verts_count_of += STEP;
                        verts = (Vertex*)realloc(verts, verts_count_of*sizeof(Vertex));
                    }
                    verts[verts_count].position[0] = vert.position[0];
                    verts[verts_count].position[1] = vert.position[1];
                    verts[verts_count].position[2] = vert.position[2];

                    verts[verts_count].normal[0] = vert.normal[0];
                    verts[verts_count].normal[1] = vert.normal[1];
                    verts[verts_count].normal[2] = vert.normal[2];

                    verts[verts_count].texcoord[0] = vert.texcoord[0];
                    verts[verts_count].texcoord[1] = vert.texcoord[1];
                    verts_count += 1;
                }
            }
        }

    }
    
    this->model_size = verts_count;
    this->model = verts;
}