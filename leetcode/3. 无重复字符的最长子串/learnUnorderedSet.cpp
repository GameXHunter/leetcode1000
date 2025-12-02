/*
* unordered_set练习
*/
#include<unordered_set>
#include<set>
#include<string>
#include<iostream>
/*
#include<vector>
#include<list>
*/
//using namespace std;


//手写一个简易哈希表，支持insert和find
class SimpleHashSet {
private:
	std::vector<std::list<std::string>>  buckets;
	size_t num_buckets;

	//哈希函数：字符串 ->index
	size_t hash(const std::string& key)
	{
		size_t h = 0;
		for (char c : key)
		{
			h = h * 31 + static_cast<unsigned char>(c);// 多项式哈希
		}

		size_t result = h % num_buckets;
		std::cout << key << " 的hash结果为" << result << std::endl;
		return result;
	}


public:
	SimpleHashSet(size_t size = 10) :num_buckets(size) {
		buckets.resize(num_buckets);
	}

	void insert(const std::string& key)
	{
		size_t idx = hash(key);
		if (std::find(buckets[idx].begin(), buckets[idx].end(), key) == buckets[idx].end())
		{
			buckets[idx].push_back(key);
		}
	}

	bool find(const std::string& key)
	{
		size_t idx = hash(key);
		auto& bucket = buckets[idx];
		 return std::find(bucket.begin(), bucket.end(), key) != bucket.end();
	}

	void print()
	{
		for (size_t i = 0; i < num_buckets; ++i)
		{
			std::cout << "Bucket " << i << ": ";
			for (const auto& s : buckets[i]) {
				std::cout << s << " ";
			}
			std::cout << "\n";
		}
	}

};

void usage_unordered_set()
{
	std::unordered_set<char> letters;

	std::string word = "helloX";

	for (char c : word)
	{
		if (letters.count(c))
		{
			std::cout << c << "是重复的" << std::endl;
		}
		else {
			letters.insert(c);
			std::cout << "加入 '" << c << "'" << std::endl;
		}
	}

	std::cout << "总共 " << letters.size() << " 个不重复字符。" << std::endl;

	//letters.erase('X');
	auto it = letters.find('x');
	if (it != letters.end()) {
		letters.erase(it); // 安全删除
	}

	std::cout << "移除X后，是 ";

	for (char c : letters)
	{
		std::cout << c;
	}

}

void compare_set_unorderedset()
{
	std::set<int> s1 = { 3,4,5,1,2 };
	std::unordered_set<int> s2 = { 3,4,5,1,2 };

	std::cout << "set是有序的：";
	for (int s : s1) std::cout << s; //输出：12345

	std::cout << "\n unordered_set是无序的 ："; //输出：34512
	for (int s : s2) std::cout << s;


}

void setTest()
{
	SimpleHashSet set(5); // 5个桶
	set.insert("apple");
	set.insert("banana");
	set.insert("cherry");
	set.insert("date");

	set.print();

	std::cout << "\nFind 'apple': " << (set.find("apple") ? "Yes" : "No") << "\n";
	std::cout << "Find 'grape': " << (set.find("grape") ? "Yes" : "No") << "\n";

}

int main_test()
{
	//usage_unordered_set();
	//compare_set_unorderedset();
	setTest();
	return 0;
}