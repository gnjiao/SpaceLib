/*
----------------------------------------------------------------------------
 TRIANGLE.C

		Università degli Studi di Brescia
		Dipartimento di Ingegneria Meccanica ed Industriale
		Via Branze 38
		25123 BRESCIA - ITALY

		giovanni.legnani @ unibs.it
-----------------------------------------------------------------------------
*/
#include <stdio.h>
#include <math.h>
#include "SPACELIB.H"

int main(void)
{
	MAT4 m01,m02,m10;   /* position matrices */
	MAT4 Q;             /* rototranslation matrix */

	POINT P1={0,1,2,1}; /* points of the triangle in the starting position */
	POINT P2={0,6,2,1};
	POINT P3={0,1,6,1};

	POINT P4={3,0,2,1}; /* points of the triangle in the final position */
	POINT P5={8,0,2,1};
	POINT P6={3,0,6,1};

	AXIS u;             /* rototranslation axis */
	POINT P;            /* point of the rototranslation axis */
	real phi;            /* rotation angle */
	real h;             /* pitch of the screw */

	frame4P(P1,P2,P3,Y,Z,m01);  /* builds starting position matrix */
	frame4P(P4,P5,P6,Y,Z,m02);  /* builds final position matrix */

	invers(m01,m10);            /* builds the rototranslation matrix Q */
	molt4(m02,m10,Q);

	mtoscrew(Q,u,&phi,&h,P);     /* extracts the rototranslation parameters from Q */

                               /* output results */
	printm4("The position matrix m10 is:",m10);
	printm4("The position matrix m02 is:",m02);
	printm4("The rototranslation matrix is:",Q);
	printv("\nThe axis u is:",u,3);
	printf("\nThe rotation angle is "PRIr":",phi);
	printf("\nThe pitch is "PRIr":",h);
	printv("\nThe point of the axis is:",P,4);
	return(0);
}
