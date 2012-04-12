// ***********************************************************************
// ecdsa.h
// ***********************************************************************
//
// This describes functions, types and constants exported and used by ecdsa.c
//
// This file is licensed as described by the file LICENCE.

#ifndef ECDSA_H_INCLUDED
#define ECDSA_H_INCLUDED

#include "common.h"
#include "bignum256.h"

// A point on the elliptic curve, in affine coordinates. Affine
// coordinates are the (x, y) that satisfy the elliptic curve
// equation y ^ 2 = x ^ 3 + a * x + b.
typedef struct PointAffineStruct
{
	u8 x[32];
	u8 y[32];
	// If is_point_at_infinity is non-zero, then this point represents the
	// point at infinity and all other structure members are considered
	// invalid.
	u8 is_point_at_infinity;
} PointAffine;

extern void setToG(PointAffine *p);
extern void setFieldToP(void);
extern void pointMultiply(PointAffine *p, BigNum256 k);
extern u8 ecdsaSign(BigNum256 r, BigNum256 s, BigNum256 hash, BigNum256 privatekey, BigNum256 k);

#endif // #ifndef ECDSA_H_INCLUDED
