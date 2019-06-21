#pragma once
#include <string>
#include <vector>
using namespace std;



class StringHelper {
public:
	StringHelper();
	~StringHelper();
public:
	//��wstringת����string
	static string Wstring2String(wstring wstr);
	//��stringת����wstring
	static wstring String2Wstring(string str);
	//�ַ�����ȡ
	static int SubString(wchar_t* tCh, int startPos, int length, wchar_t* outSubStr);
	//��UTF-8ת��Unicode
	static long UTF8ToUnicode(char* cUTF8, wchar_t wcUnicode[]);
	//���ַ���Сдת�ɴ�д
	static long ToUpper(char* lower, char* upper);
	static wstring ANSIToUnicode(const string& str);
	static string UnicodeToUTF8(const wstring& str);
	static wstring UTF8ToUnicode(const string& str);
	static string UnicodeToANSI(const wstring& str);
public:
	//��ȡ�ַ����ĳ��ȣ�ռ�õ��ڴ��ֽڳ���,���Ҵ�\0��β��
	static long GetStringMemLength(const char *ch);
	//��ȡ�ַ����ĳ���,ռ�õ��ڴ��ֽڳ���,���Ҵ�\0��β��
	static long GetStringMemLength(const wchar_t *ch);
	//��ȡ�ַ����ĳ��ȣ�ռ�õ��ڴ��ֽڳ���,���Ҵ�\0��β��
	static long GetStringTCHARMemLength(const wchar_t* ch);
public:
	//����JSONͨ�����ƻ�ȡֵ��JSON��:{},ֻ��һ������
	static long AnalysisJsonValue(TCHAR* json, TCHAR* inKey, TCHAR* outVaule);
	//�ж��ַ����Ƿ�Ϊ��
	static BOOL IsEmpty(TCHAR* tCh);
	//�ж��ַ����Ƿ�Ϊ��
	static BOOL IsEmpty(char* tCh);
	//�ַ����Ƚ�
	static BOOL Equals(TCHAR* source, TCHAR* desc);
	//�ַ����Ƚ�
	static BOOL Equals(char* source, char* desc);
	//ȥ����β�ո�
	static TCHAR* Trim(TCHAR* pCh);
	//�ַ����ָ�
	static vector< string> split(string str, string pattern);
	//ȥ����β�ո�
	static string& trim(std::string &s);
	//�ַ����滻
	static string& string_replace(std::string &strBig, const std::string &strsrc, const std::string &strdst);
	//��ȡ�����,bits������ĸ���
	static string GetRandomNumber(int bits);
	/* {{{ URL���룬��ȡ��PHP
	*	�÷���string urlencode(string str_source)
	*	˵������������ -_. ����ȫ�����룬�ո�ᱻ����Ϊ +
	*/
	static string UrlEncode(string &str_source);

	/* {{{ URL���룬��ȡ��PHP 5.2.17
	*	�÷���string urldecode(string str_source)
	*	ʱ�䣺2012-8-14 By Dewei
	*/
	static string UrlDecode(string &str_source);

	static int htoi(char *s);

	/**
	* �ж��ַ����Ƿ���start��ͷ
	*/
	static bool startswith(const std::string& str, const std::string& start);

	/**
	* �ж��ַ����Ƿ���end�ַ�������
	*/
	static bool endswith(const std::string& str, const std::string& end);
};
