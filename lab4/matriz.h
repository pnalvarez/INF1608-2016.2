double** mat_cria(int m, int n);
void mat_libera(int m, double** A);
void mat_transposta(int m,int n, double** A,double** T);
void mat_imprime(int m, int n, double** A);
void mat_multv(int m, int  n,double** A,double* v, double* w);
void mat_multm (int m, int n, int q, double** A, double** B, double** c);
void mat_preenche(int m,int n, double** A);