
//1�����������
//2�����������ܵ���������
//3 ���ִ���

//1д�����ļ�
	//��������ʲô�ط�д��дkey дvalude
	//int WriteIniCfg(FILE*fp, char *key, char *valude ); //������
	int WriteIniCfg(const char *pfile /*in*/, char *key /*in */, char *valude /*in*/); //����Ľ��нӿڷ�װ

//2 �������ļ�
	int  ReadIniCfg(const char *pfile, char *key, char *valude);
//	3���޸������ļ�

	int ModifyIniCfg(const char *pfile, char *key, char *valude);

	//����������У��ӿ�Ҫ�������ģ��Ҫ���ɡ���������


	