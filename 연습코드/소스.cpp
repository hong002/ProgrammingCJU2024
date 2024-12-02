#include <stdio.h>

void SetArray(double* pDArr, int nArrSize)
{
	printf("input: size(%d) array\n", nArrSize);
	for (unsigned int i = 0; i < nArrSize; i++)
	{
		scanf_s("%lf", pDArr + i);
	}
}

void PrintArray(double* pDArr, int nArrSize)
{
	printf("using pointer..\n");
	for (unsigned int i = 0; i < nArrSize; i++)
	{
		printf("[%d](%u, %.4lf)\n", i, pDArr + i, *(pDArr + i));
	}
}

double CalcMaxValArry(double* pDArr, int nArrSize)
{
	double dRes = *(pDArr + 0);
	for (unsigned int i = 0; i < nArrSize; i++)
	{
		if (*(pDArr + i) > dRes)
			dRes = *(pDArr + i);
	}
	return dRes;
}

int main(void)
{
	double dArr[5] = {};
	double* pDArr = dArr;
	const int nArrSize = sizeof(dArr) / sizeof(dArr[0]);

	SetArray(pDArr, nArrSize);
	PrintArray(pDArr, nArrSize);

	printf("\n");
	printf("using array..\n");

	for (unsigned int i = 0; i < nArrSize; i++)
	{
		// printf("[%d](%u, %.4lf)\n", i, &dArr[i], dArr[i]);
		printf("[%d](%u, %.4lf)\n", i, dArr + i, *(dArr + i));
	}

	printf("\n");
	printf("using compatability..\n");
	for (unsigned int i = 0; i < nArrSize; i++)
	{
		printf("[%d](%u, %.4lf)\n", i, &dArr[i], dArr[i]);
		printf("[%d](%u, %.4lf)\n", i, dArr + i, *(dArr + i));
		printf("[%d](%u, %.4lf)\n", i, &pDArr[i], pDArr[i]);
		printf("[%d](%u, %.4lf)\n", i, pDArr + i, *(pDArr + i));            // 모두 호환 가능하다  (괄호 범위, 엔드문자 주의해서)
	}

	printf("[MaxVal](%.4lf)\n", CalcMaxValArry(pDArr, nArrSize));

	return 0;
}