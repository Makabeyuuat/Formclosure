#include <stdio.h>
#include <math.h>

#include "mathFunc.h"

#define N 3

//�x�W�F�Ȑ�
double Rx(double* b, double* q, int j) {
	int i;
	double ret = 0.0;
	double temp = 0.0;

	for (i = 0; i <= N; i++) {
		ret += b[i] * (factorial(N) / (factorial(N - i) * factorial(i))) * pow(q[j], i) * pow((1 - q[j]), N - i);
		temp += (factorial(N) / (factorial(N - i) * factorial(i)));
		//printf("%.7lf\n", temp);
	}
	return(ret);
}
double Ry(double* b, double* q, int j) {
	int i;
	double ret = 0.0;

	for (i = 0; i <= N; i++) {
		ret += b[i] * (factorial(N) / (factorial(N - i) * factorial(i))) * pow(q[j], i) * pow((1 - q[j]), N - i);

	}
	return(ret);
}


//�x�W�F�Ȑ���1�K����
double d1Rxdq1(double* b, double* q, int j) {
	int i;
	double ret = 0.0;

	for (i = 1; i <= N; i++) {
		ret += (-b[i - 1] + b[i]) * (factorial(N) / (factorial(N - i) * factorial(i))) * i * pow(q[j], i - 1) * pow((1 - q[j]), N - i);

	}
	return(ret);
}
double d1Rydq1(double* b, double* q, int j) {
	int i;
	double ret = 0.0;

	for (i = 1; i <= N; i++) {
		ret += (-b[i - 1] + b[i]) * (factorial(N) / (factorial(N - i) * factorial(i))) * i * pow(q[j], i - 1) * pow((1 - q[j]), N - i);

	}
	return(ret);
}


//�x�W�F�Ȑ���2�K����
double d2Rxdq2(double* b, double* q, int j) {
	int i;
	double ret = 0.0;

	for (i = 2; i <= N; i++) {
		ret += (b[i] - 2 * b[i - 1] + b[i - 2])
			* (factorial(N) / (factorial(N - i) * factorial(i))) * i * (i - 1) * pow(q[j], i - 2) * pow((1 - q[j]), N - i);

	}
	return(ret);
}

double d2Rydq2(double* b, double* q, int j) {
	int i;
	double ret = 0.0;

	for (i = 2; i <= N; i++) {
		ret += (b[i] - 2 * b[i - 1] + b[i - 2])
			* (factorial(N) / (factorial(N - i) * factorial(i))) * i * (i - 1) * pow(q[j], i - 2) * pow((1 - q[j]), N - i);

	}
	return(ret);
}

//�x�W�F�Ȑ���3�K����
double d3Rxdq3(double* b, double* q, int j) {
	int i;
	double ret = 0.0;

	for (i = 3; i <= N; i++) {
		ret += (b[i] - 3 * b[i - 1] + 3 * b[i - 2] - b[i - 3])
			* (factorial(N) / (factorial(N - i) * factorial(i))) * i * (i - 1) * (i - 2) * pow(q[j], i - 3) * pow((1 - q[j]), N - i);

	}
	return(ret);
}
double d3Rydq3(double* b, double* q, int j) {
	int i;
	double ret = 0.0;

	for (i = 3; i <= N; i++) {
		ret += (b[i] - 3 * b[i - 1] + 3 * b[i - 2] - b[i - 3])
			* (factorial(N) / (factorial(N - i) * factorial(i))) * i * (i - 1) * (i - 2) * pow(q[j], i - 3) * pow((1 - q[j]), N - i);

	}
	return(ret);
}


//�x�W�F�Ȑ���4�K����
double d4Rxdq4(double* b, double* q, int j) {
	int i;
	double ret = 0.0;

	for (i = 4; i <= N; i++) {
		ret += (b[i] - 4 * b[i - 1] + 6 * b[i - 2] - 4 * b[i - 3] + b[i - 4])
			* (factorial(N) / (factorial(N - i) * factorial(i))) * i * (i - 1) * (i - 2) * (i - 3) * pow(q[j], i - 4) * pow((1 - q[j]), N - i);

	}
	return(ret);
}
double d4Rydq4(double* b, double* q, int j) {
	int i;
	double ret = 0.0;

	for (i = 4; i <= N; i++) {
		ret += (b[i] - 4 * b[i - 1] + 6 * b[i - 2] - 4 * b[i - 3] + b[i - 4])
			* (factorial(N) / (factorial(N - i) * factorial(i))) * i * (i - 1) * (i - 2) * (i - 3) * pow(q[j], i - 4) * pow((1 - q[j]), N - i);

	}
	return(ret);
}

//�m�����v�Z
double norm(double* bx, double* by, double* q, int j) {
	double ret = 0.0;
	ret = sqrt(pow(d1Rxdq1(bx, q, j), 2) + pow(d1Rydq1(by, q, j), 2));

	return(ret);
}