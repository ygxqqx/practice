// 互斥锁和条件等待 解决生产者和消费者模型

条件等待模型
//socket连接池。。。。。

		pthread_mutex_lock(&mutex);
	
		while (g_Count == 0)  //while 醒来以后需要重新判断 条件g_Count是否满足，如果不满足，再次wait
		{	
			pthread_cond_wait(&my_condition, &mutex);（解锁、等待、加锁
		}
	
		g_Count --
		pthread_mutex_unlock(&mutex);
	
发送条件成立模型

		pthread_mutex_lock(&mutex);	
		g_Count++;
		pthread_cond_signal(&my_condition); //通知，在条件上等待的线程 		
		pthread_mutex_unlock(&mutex);

//

多线程同步问题：
线程共享进程的资源和地址空间
任何线程对系统资源的操作都会给其他线程带来影响
多线程同步方法：
互斥锁（线程锁。。。。。） ，线程库提供的   
====》进程A）创建了10个线程 进程B创建20线程
因为我要在某一个进程上定义一个线程锁mutextA，请问进程不能用mutextA。
信号量（同步进程，同步线程）IPC机制，直接归内管理
条件变量
