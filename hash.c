#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define    HASHSIZE 256 

//简单hash实现 内部冲突采用单链表组织


//读写锁控制线程安全
//桶节点加锁

//定义冲突链中的节点的类型  
struct list{ 
    struct list *next; 
    unsigned int value; 
}; 


//static struct list *hashtab[HASHSIZE];

//定义hash节点
struct hash_node{
	struct list * node;
	pthread_rwlock_t rwlock;
}
static struct hash_node *hashtab[HASHSIZE];

//hash函数
unsigned int hash(unsigned int value)
{
    unsigned int hashval;
    hashval  = value
    return hashval % HASHSIZE;
}

//查找节点
struct list *find_node(unsigned int value)
{
    struct list *p;
	unsigned int key = hash(value)
	struct hash_node *head = hashtab[key]
	pthread_rwlock_rdlock(&(head->rwlock));

    for(p=head->node;p != NULL;p = p->next)
	{
		if(p->value == value)
		{
			pthread_rwlock_unlock(&(head->rwlock))
			return p;
		}
	}
	pthread_rwlock_unlock(&(head->rwlock))
    return NULL;
}

//添加节点
struct list *add_node(unsignd int value)
{
    struct list *p = NULL;
	
	struct hash_node *head = hashtab[hash(value)];
	pthread_rwlock_wrlock(&(head->rwlock));
	
	for(p=head->node;p != NULL;p = p->next)
	{
		if(p->value == value)
		{
			pthread_rwlock_unlock(&(head->rwlock))
			return p;
		}
	}
	p = (struct list *)malloc(sizeof(struct list));
	if(p == NULL)
	{
		pthread_rwlock_unlock(&(head->rwlock));
		return NULL;
	}

	//头插
	p->value = value;
	p->next = head->node;
	head->node = p;
	pthread_rwlock_unlock(&(head->rwlock));	
	return p;
}


//删除节点
void delete_node(unsigned int value)
{
	struct list  *p = NULL;
	struct list  *q = NULL;
	struct list  *r = NULL;
	struct hash_node  *head = hashtab[hash(value)];

	pthread_rwlock_wrlock(&(head->rwlock));
	p = head->node;
    while(p)
	{
		q = p->next;
		if (p->value == value)
		{
			if (r == NULL)
			{
				free(p);
				p = NULL;
				pthread_rwlock_unlock(&(head->rwlock));
				return;
			}
			else
			{
				r->next = q;
				free(p)
				p = NULL;
				pthread_rwlock_unlock(&(head->rwlock));
				return;
			}
		}
		r = p;
		p = q;
	}
	pthread_rwlock_unlock(&(head->rwlock));	
}
