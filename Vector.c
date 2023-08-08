//
// Created by andre on 4/22/2023.
//

#include "Vector.h"

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

Vector2 AllocateVector2() {
    return (Vector2) malloc(VECTOR2_SIZE);
}

Vector3 AllocateVector3() {
    return (Vector3) malloc(VECTOR3_SIZE);
}

Vector2 InitVector2(double x, double y) {
    Vector2 vector = AllocateVector2();
    vector->x = x;
    vector->y = y;
    return vector;
}

Vector3 InitVector3(double x, double y, double z) {
    Vector3 vector = AllocateVector3();
    vector->x = x;
    vector->y = y;
    vector->z = z;
    return vector;
}

Vector2 Vector_Up() {
    return InitVector2(0, 0);
}

Vector2 Vector2_Right() {
    return InitVector2(1, 0);
}

Vector3 Vector3_Up() {
    return InitVector3(0, 1, 0);
}

Vector3 Vector3_Right() {
    return InitVector3(1, 0, 0);
}

Vector3 Vector3_Forward() {
    return InitVector3(0, 0, 1);
}

Vector3 Vector3_Zero() {
    return InitVector3(0, 0, 0);
}

Vector3 Vector3_One() {
    return InitVector3(1, 1, 1);
}


Vector2 Vector2_Sum(Vector2 v, Vector2 v2) {
    return InitVector2(
            v->x + v2->x,
            v->y + v2->y
    );
}

Vector3 Vector3_Sum(Vector3 v, Vector3 v2) {
    return InitVector3(
            v->x + v2->x,
            v->y + v2->y,
            v->z + v2->z
    );
}

Vector2 Vector2_Mul(double num, Vector2 v) {
    return InitVector2(
            num * (v->x),
            num * (v->y)
    );
}

Vector3 Vector3_Mul(double num, Vector3 v) {
    return InitVector3(
            v->x *= num,
            v->y *= num,
            v->z *= num
    );
}

double Vector2_ScalarProduct(Vector2 v, Vector2 v2) {
    return v->x * v2->x + v2->y * v2->y;
}

double Vector3_ScalarProduct(Vector3 v, Vector3 v2) {
    return v->x * v2->x + v2->y * v2->y + v->z * v2->z;
}

Vector3 Vector3_VectorialProduct(Vector3 v, Vector3 v2) {
    return InitVector3(
            v->y * v2->z + v->z * v2->y,
            v->z * v2->x + v->x * v2->z,
            v->x * v2->y + v->y * v2->x
    );
}

double Vector2_Module(Vector2 v) {
    return sqrt(
            pow(v->x, 2) + pow(v->y, 2)
    );
}

double Vector3_Module(Vector3 v) {
    return sqrt(
            pow(v->x, 2) + pow(v->y, 2) + pow(v->z, 2)
    );
}

void Vector2_Normalize(Vector2 v) {
    const double module = Vector2_Module(v);
    v->x /= module;
    v->y /= module;
}

void Vector3_Normalize(Vector3 v) {
    const double module = Vector3_Module(v);
    v->x /= module;
    v->y /= module;
    v->z /= module;
}

void Vector2_Print(Vector2 v) {
    printf("Vector:\nx: %lf y: %lf\n", v->x, v->y);
}

void Vector3_Print(Vector3 v) {
    printf("Vector:\nx: %lf y: %lf z: %lf\n", v->x, v->y, v->z);
}
