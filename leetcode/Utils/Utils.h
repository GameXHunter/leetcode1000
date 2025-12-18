#pragma once

#include<vector>
#include<string>
#include<iostream>

struct ListNode {
	int val;
	ListNode* next;
	ListNode() :val(0), next(nullptr) {}
	ListNode(int x) :val(x), next(nullptr) {}
	ListNode(int x, ListNode* next) :val(x), next(next) {}
};

class Utils {

public:

	//使用模板泛化
	template<typename T>
	static void print_vector(const std::vector<T>& vec)
	{
		std::cout << "[";
		for (int i = 0; i < vec.size(); ++i) {
			if (i > 0) std::cout << ",";

			std::cout << vec[i] ;
		}
		std::cout << "]" << std::endl;
	}


	template<typename T>
	static void print_vector_vector(const std::vector<std::vector<T>>& vec)
	{
		std::cout << "[" << std::endl;
		for (int i = 0; i < vec.size(); ++i) {
			//if (i > 0) std::cout << "," << std::endl;
			print_vector(vec[i]);  // 复用已有的 print_vector 函数
		}
		std::cout << "]" << std::endl;
	}



	template<typename T>
	static ListNode* createList(const std::vector<T>& vec)
	{
		if (vec.empty()) return nullptr;
		ListNode* head = new ListNode(vec[0]);

		ListNode* curr = head;

		for (int i = 1; i < vec.size(); ++i)
		{
			curr->next = new ListNode(vec[i]);
			curr = curr->next;
		}
		return head;

	}
	static void print_list(ListNode* list)
	{
		std::cout << "[";
		while (list != nullptr)
		{
			std::cout << list->val;
			list = list->next;
			if (list != nullptr)std::cout << "->";
		}
		std::cout << "]" << std::endl;
	}




};