
//1、分清出功能
//2、分析出功能的输入和输出
//3 兑现代码

//1写配置文件
	//参数：向什么地方写、写key 写valude
	//int WriteIniCfg(FILE*fp, char *key, char *valude ); //不合理
	int WriteIniCfg(const char *pfile /*in*/, char *key /*in */, char *valude /*in*/); //合理的进行接口封装

//2 读配置文件
	int  ReadIniCfg(const char *pfile, char *key, char *valude);
//	3、修改配置文件

	int ModifyIniCfg(const char *pfile, char *key, char *valude);

	//在软件开发中，接口要求紧，，模块要求松。。。。。


	