/*
----------------------------------------------------------------------------
MTOSCREW.C:
  Example of function  mtoscrew().  For detail see User's Manual.

		Università degli Studi di Brescia
		Dipartimento di Ingegneria Meccanica ed Industriale
		Via Branze 38
		25123 BRESCIA - ITALY

                giovanni.legnani @ unibs.it
-----------------------------------------------------------------------------
*/
#include <stdio.h>
#include "SPACELIB.H"

int main (void)
{
	MAT4 Q= { {0., 1., 0., 0.},
		 {-1., 0., 0., 2.},
		  {0., 0., 1., 0.},
		  {0., 0., 0., 1.} };
	AXIS u;
	real phi,h;
	POINT P;

	mtoscrew(Q,u,&phi,&h,P);

	printv("The axis u is :",u,3);
	printf("\nThe angle phi is : "PRIr"\n",phi);
	printf("\nThe pitch h is : "PRIr"\n",h);
	printv("The point P is :",P,4);
	return(0);
}
