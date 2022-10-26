#include<iostream>
#include<string>
using namespace std;

typedef struct Str {
	char* ch;
	int length;
};

int strAssign(Str* str, char* ch)  //串赋值
{
	int i, j = 0;
	if (str->ch) {
		free(str->ch);
	}
	i = strlen(ch);
	if (i == 0) {
		str->ch = NULL;
		str->ch = 0;
	}
	else {
		str->ch = (char*)malloc(i * sizeof(char));
		for (j = 0; j < i; j++) {
			str->ch[j] = ch[j];
		}
		str->length = i;
	}
	return 0;
}

int Length(Str S)  //求串长
{
	return S.length;
}

void StrCat(Str* s, Str t1, Str t2)  //串连接
{
	int i;
	if (s->ch)
		free(s->ch);
	s->length = t1.length + t2.length;
	s->ch = (char*)malloc(s->length * sizeof(char)); if (!s->ch)
		exit(OVERFLOW);
	for (i = 0; i < t1.length; i++)
		s->ch[i] = t1.ch[i]; for (i = 0; i < t2.length; i++)
		s->ch[t1.length + i] = t2.ch[i];
}

int StrLength(char s[]) //求串长
{
	int i = 0;
	while (s[i] != '\0') {
		i++;
	}
	return i;
}

int* multi_BF(char S[], char T[]) //BF算法支持多次匹配
{
	int S_length = StrLength(S);
	int T_length = StrLength(T);
	int start = 0;
	int i = 0, j = 0, k = 0;
	int* a = new int[S_length] {0};
	while (i < S_length) {
		while ((i < S_length) && (j < T_length)) {
			if (S[i] == T[j]) {
				i++;
				j++;
			}
			else {
				start++;
				i = start;
				j = 0;
			}
		}
		if (j == T_length) {
			a[k] = start + 1;
			k++;
			j = 0;
		}
		start = i;
	}
	return a;
}

int* getNext(char T[])  // 声明next数组
{
	int T_len = StrLength(T);
	int* next = new int[T_len];
	int i = 0;
	int j = -1;
	next[0] = -1;
	while (i < T_len)
	{
		if (j == -1 || T[i] == T[j])
		{
			next[++i] = ++j;
		}
		else
			j = next[j];
	}
	return next;
}

int KMP(char S[], char T[], int* next)  //KMP算法
{
	int S_length = StrLength(S);
	int T_length = StrLength(T);
	int i = 0, j = 0;
	while ((i < S_length) && (j < T_length))
	{
		if (S[i] == T[j])
		{
			i++; j++;
		}
		else
		{
			j = next[j];
			if (j == -1)
			{
				i++; j++;
			}
		}
	}
	if (j == T_length)
		return i - j + 1;
	else return 0;
}

/*int main()
{
	char S[] = "abcabcababde";
	char T[] = "abc";
	int* bf = multi_BF(S, T);
	for (int b = 0; bf[b] != 0; b++) {
		cout << "BF匹配成功的位置为：" << bf[b] << endl;
	}
	int* next = getNext(T);
	int num = KMP(S, T, next);
	cout << "KMP匹配成功的位置为：" << num << endl;
	system("pause");
	return 0;
}*/