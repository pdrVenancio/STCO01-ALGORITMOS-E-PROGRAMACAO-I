typedef struct complexo
{
  double real, imag;
}complexo;

complexo *complexoCriar(double real, double imag);

complexo *complexoLe();

complexo *complexoSub(complexo *n1, complexo *n2);
complexo *complexoSoma(complexo *n1, complexo *n2);
complexo *complexoMult(complexo *n1, complexo *n2);
complexo *complexoDiv(complexo *n1, complexo *n2);

void complexoPrint(complexo *n);
void complexoLiberar(complexo *n);




