#pragma once
template <typename elemname>
class Node {
public:
	Node<elemname>() {

	}
	Node<elemname>(elemname input_element) :element_(input_element) {
		//初始化
	}
	void setNext(Node<elemname>* input) {
		this->NextPlace_ = input;  //设置下一个节点
	}
	Node<elemname>* NextP()const {
		return NextPlace_;		//返回下一个节点的地址
	}
	elemname& getElement() {
		return element_;		//获得存储的元素
	}
private:
	elemname element_;
	Node<elemname>* NextPlace_ = 0;  //单向链表
};
