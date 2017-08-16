/* 
You are given a string, s, and a list of words, words, that are all of the same length. 
Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.

For example, given:
s: "barfoothefoobarman"
words: ["foo", "bar"]

You should return the indices: [0,9].
(order does not matter).

*/
#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <map>
using namespace std;

class Solution {
public:
	//校验方式
	vector<int> findSubstring1(string s, vector<string>& words) {
		vector<int> ret;
		//判空
		if (words.empty() || s.empty() || words[0].size() == 0)
			return ret;
		int i,j;
		int sLen = s.size();
		int wordsLen = words.size();
		int wordLen = words[0].size();
		int wordsCharLen = wordsLen * wordLen;
		map<string,int> dict;
		map<string,int>::iterator dictIt;
		int dictLen;
		int *dictItemNum;
		int sCheckNum = 0;
		int wordsCheckNum = 0;
		if (sLen < wordsCharLen)
			return ret;
		//建立words的表
		for (i=0; i<wordsLen; i++)
		{
			dictIt = dict.find(words[i]);
			if (dictIt != dict.end())
				dictIt->second ++;
			else
				dict.insert(pair<string,int>(words[i],1));
		}
		dictLen = dict.size();
		//存储dict的value
		dictItemNum = new int[dictLen];
		for (i=0,dictIt=dict.begin(); dictIt!=dict.end(); dictIt++,i++)
			dictItemNum[i] = dictIt->second;
		//建立words的校验和
		for (i=0; i<wordsLen; i++)
			for (j=0; j<wordLen; j++)
				wordsCheckNum += words[i][j];
		//先计算s的前wordsSumLen的校验和
		for (i=0; i<wordsCharLen; i++)
			sCheckNum += s[i];
		//依次比较
		for (i=0; i<sLen-wordsCharLen+1; i++)
		{
			//当前校验和
			if (sCheckNum == wordsCheckNum)
			{
				bool isMatch = true;
				for (j=0,dictIt=dict.begin(); dictIt!=dict.end(); dictIt++,j++)
					dictIt->second = dictItemNum[j];
				for (j=0; j<wordsLen; j++)
				{
					dictIt = dict.find(s.substr(i+j*wordLen,wordLen));
					if (dictIt == dict.end() || dictIt->second == 0)
					{
						isMatch = false;
						break;
					}
					else
					{
						dictIt->second --;
					}
				}
				if (isMatch)
					ret.push_back(i);
			}
			//计算下次校验和
			if (i+wordsCharLen >= sLen)
				break;
			sCheckNum -= s[i];
			sCheckNum += s[i+wordsCharLen];
		}
		return ret;
	}
	//无校验方式
	vector<int> findSubstring2(string s, vector<string>& words) {
		vector<int> ret;
		//判空
		if (words.empty() || s.empty() || words[0].size() == 0)
			return ret;
		int i,j;
		int sLen = s.size();
		int wordsLen = words.size();
		int wordLen = words[0].size();
		int wordsCharLen = wordsLen * wordLen;
		map<string,int> dict;
		map<string,int>::iterator dictIt;
		int dictLen;
		int *dictItemNum;
		if (sLen < wordsCharLen)
			return ret;
		//建立words的表
		for (i=0; i<wordsLen; i++)
		{
			dictIt = dict.find(words[i]);
			if (dictIt != dict.end())
				dictIt->second ++;
			else
				dict.insert(pair<string,int>(words[i],1));
		}
		dictLen = dict.size();
		//存储dict的value
		dictItemNum = new int[dictLen];
		for (i=0,dictIt=dict.begin(); dictIt!=dict.end(); dictIt++,i++)
			dictItemNum[i] = dictIt->second;
		//依次比较
		for (i=0; i<sLen-wordsCharLen+1; i++)
		{
			bool isMatch = true;
			for (j=0,dictIt=dict.begin(); dictIt!=dict.end(); dictIt++,j++)
				dictIt->second = dictItemNum[j];
			for (j=0; j<wordsLen; j++)
			{
				dictIt = dict.find(s.substr(i+j*wordLen,wordLen));
				if (dictIt == dict.end() || dictIt->second == 0)
				{
					isMatch = false;
					break;
				}
				else
				{
					dictIt->second --;
				}
			}
			if (isMatch)
				ret.push_back(i);
		}
		return ret;
	}
	//网上最常见方式
	vector<int> findSubstring3(string s, vector<string>& words) {
		map<string,int> dict,cur;
		int wordsLen = words.size();
		int wordLen = words[0].size();
		int sLen = s.size();
		vector<int> ret;
		for(int k=0; k<wordsLen; k++)
			dict[words[k]]++;//初始化容器
		for(int i=0; i<=sLen-wordLen*wordsLen; i++)
		{
			cur.clear();//每次使用之前要清空，这个容器是不断变化的
			int j;
			for(j=0;j<wordsLen;j++)
			{
				string word = s.substr(i+j*wordLen,wordLen);//获取这个单词
				if(dict.find(word) == dict.end())//这个单词不是单词列表中的
					break;
				cur[word]++;
				if(dict[word] < cur[word])//出现的次数多了
					break;
			}
			if(j == wordsLen)//这时候是匹配的
				ret.push_back(i);
		}
		return ret;
	}
	//网上O(n)
	vector<int> findSubstring4(string s, vector<string> &words) {
		vector<int> ret;
		int i,j;
		int sLen = s.size();
		int wordsLen = words.size();
		if (sLen <= 0 || wordsLen <= 0) 
			return ret;
		//初始化word的dict
		//unordered_map<string, int> dict;
		map<string, int> dict;
		for (i=0; i<wordsLen; i++)
			dict[words[i]]++;

		//遍历所有子串
		int wordLen = words[0].size();
		for (i=0; i<wordLen; i++)
		{
			int left = i;
			int	count = 0;//记录连续的元素个数
			map<string, int> tdict;//缓存map
			for (j=i; j<=sLen-wordLen; j += wordLen)
			{
				string str = s.substr(j, wordLen);
				//若有效,进行计数
				if (dict.count(str))//此次元素相同
				{
					tdict[str]++;
					if (tdict[str] <= dict[str]) 
						count++;
					else 
					{
						//匹配成功,但是超过了次数,认为匹配失败,失败的话
						//从头开始遍历,从重复的位置开始计算,重复位置之前的计数-1
						while (tdict[str] > dict[str]) 
						{
							string str1 = s.substr(left, wordLen);
							tdict[str1]--;
							if (tdict[str1] < dict[str1]) 
								count--;
							left += wordLen;
						}
					}
					// come to a result
					if (count == wordsLen) {
						ret.push_back(left);
						// advance one word
						tdict[s.substr(left, wordLen)]--;
						count--;
						left += wordLen;
					}
				}
				// not a valid word, reset all vars
				else 
				{
					tdict.clear();
					count = 0;//这个小子串匹配不成功,继续后续判断
					left = j + wordLen;
				}
			}
		}
		return ret;
	}
};

void main()
{
	Solution s;
	clock_t t1,t2;
	vector<string> vs;
	vs.push_back("ab");
	vs.push_back("ba");
	t1 = clock();
	vector<int> v = s.findSubstring4("abababab",vs);
	t2 = clock();
	for (int i=0; i<v.size(); i++)
		cout<<v[i]<<endl;
	cout<<"Time Comsume: "<<t2-t1<<" ms"<<endl;
}

/*

"pjzkrkevzztxductzzxmxsvwjkxpvukmfjywwetvfnujhweiybwvvsrfequzkhossmootkmyxgjgfordrpapjuunmqnxxdrqrfgkrsjqbszgiqlcfnrpjlcwdrvbumtotzylshdvccdmsqoadfrpsvnwpizlwszrtyclhgilklydbmfhuywotjmktnwrfvizvnmfvvqfiokkdprznnnjycttprkxpuykhmpchiksyucbmtabiqkisgbhxngmhezrrqvayfsxauampdpxtafniiwfvdufhtwajrbkxtjzqjnfocdhekumttuqwovfjrgulhekcpjszyynadxhnttgmnxkduqmmyhzfnjhducesctufqbumxbamalqudeibljgbspeotkgvddcwgxidaiqcvgwykhbysjzlzfbupkqunuqtraxrlptivshhbihtsigtpipguhbhctcvubnhqipncyxfjebdnjyetnlnvmuxhzsdahkrscewabejifmxombiamxvauuitoltyymsarqcuuoezcbqpdaprxmsrickwpgwpsoplhugbikbkotzrtqkscekkgwjycfnvwfgdzogjzjvpcvixnsqsxacfwndzvrwrycwxrcismdhqapoojegggkocyrdtkzmiekhxoppctytvphjynrhtcvxcobxbcjjivtfjiwmduhzjokkbctweqtigwfhzorjlkpuuliaipbtfldinyetoybvugevwvhhhweejogrghllsouipabfafcxnhukcbtmxzshoyyufjhzadhrelweszbfgwpkzlwxkogyogutscvuhcllphshivnoteztpxsaoaacgxyaztuixhunrowzljqfqrahosheukhahhbiaxqzfmmwcjxountkevsvpbzjnilwpoermxrtlfroqoclexxisrdhvfsindffslyekrzwzqkpeocilatftymodgztjgybtyheqgcpwogdcjlnlesefgvimwbxcbzvaibspdjnrpqtyeilkcspknyylbwndvkffmzuriilxagyerjptbgeqgebiaqnvdubrtxibhvakcyotkfonmseszhczapxdlauexehhaireihxsplgdgmxfvaevrbadbwjbdrkfbbjjkgcztkcbwagtcnrtqryuqixtzhaakjlurnumzyovawrcjiwabuwretmdamfkxrgqgcdgbrdbnugzecbgyxxdqmisaqcyjkqrntxqmdrczxbebemcblftxplafnyoxqimkhcykwamvdsxjezkpgdpvopddptdfbprjustquhlazkjfluxrzopqdstulybnqvyknrchbphcarknnhhovweaqawdyxsqsqahkepluypwrzjegqtdoxfgzdkydeoxvrfhxusrujnmjzqrrlxglcmkiykldbiasnhrjbjekystzilrwkzhontwmehrfsrzfaqrbbxncphbzuuxeteshyrveamjsfiaharkcqxefghgceeixkdgkuboupxnwhnfigpkwnqdvzlydpidcljmflbccarbiegsmweklwngvygbqpescpeichmfidgsjmkvkofvkuehsmkkbocgejoiqcnafvuokelwuqsgkyoekaroptuvekfvmtxtqshcwsztkrzwrpabqrrhnlerxjojemcxel"
["dhvf","sind","ffsl","yekr","zwzq","kpeo","cila","tfty","modg","ztjg","ybty","heqg","cpwo","gdcj","lnle","sefg","vimw","bxcb"]

"abababab"
["ab","ba"]

"wordgoodgoodgoodbestword"
["word","good","best","good"]
*/