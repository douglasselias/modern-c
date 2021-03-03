typedef struct
{
  float x;
  float y;
  float z;
} Vertex;

typedef Vertex Triangle[3];

  Vertex v = {
      1.3,
      1.9,
      4.1};

  printf("point X: %.2f \n", v.x);

  Triangle t = {v, v, v};

  printf("vertex 0_Z: %.2f \n", t[0].z);