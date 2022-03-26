#pragma once
#include "Node.h"
#include <iostream>
template <typename elemtype>
class LinkedList {
public:
	void Print_cout()const;		//打印全部元素
	LinkedList(){
		root_pointer_ = new Node<elemtype>;		//利用节点初始化
		last_node_ = root_pointer_;
	}
	LinkedList(elemtype input) {
		root_pointer_ = new Node<elemtype>(input);		//利用节点初始化
		last_node_ = root_pointer_;
	}
	~LinkedList() {
		if (!is_sub_) {
			this->erase();  //对非子list析构
		}
	}
	void pop(unsigned place=0);
	void erase() {
		for (; root_pointer_ != last_node_;) {
			this->pop();
		}
		this->pop();
	}
	bool empty() {
		return this->root_pointer_ == 0;
	}
	void merge(LinkedList<elemtype>&);
	void push_back(elemtype);
	void push_front(elemtype);
	void insert(elemtype, unsigned place=0);  //某位置之后插入
	void insert(elemtype, Node<elemtype>*);  //位置用指针表示的形式
	unsigned size()const;
	Node<elemtype>* getPlacePointer(unsigned)const;
	elemtype& operator[](unsigned);
private:
	Node<elemtype>* root_pointer_ = 0;	//根节点
	Node<elemtype>* last_node_ = 0;	//最后的节点（无后继）
	bool is_sub_;  //标记该list为子list，之前没有这个参数会先析构子list产生bug
};