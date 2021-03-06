
| [English](README_EN.md) | 简体中文 |

# [332. 重新安排行程](https://leetcode-cn.com/problems/reconstruct-itinerary/)

## 题目描述

<p>给定一个机票的字符串二维数组 <code>[from, to]</code>，子数组中的两个成员分别表示飞机出发和降落的机场地点，对该行程进行重新规划排序。所有这些机票都属于一个从 JFK（肯尼迪国际机场）出发的先生，所以该行程必须从 JFK 开始。</p>

<p>&nbsp;</p>

<p><strong>提示：</strong></p>

<ol>
	<li>如果存在多种有效的行程，请你按字符自然排序返回最小的行程组合。例如，行程 [&quot;JFK&quot;, &quot;LGA&quot;] 与 [&quot;JFK&quot;, &quot;LGB&quot;] 相比就更小，排序更靠前</li>
	<li>所有的机场都用三个大写字母表示（机场代码）。</li>
	<li>假定所有机票至少存在一种合理的行程。</li>
	<li>所有的机票必须都用一次 且 只能用一次。</li>
</ol>

<p>&nbsp;</p>

<p><strong>示例 1：</strong></p>

<pre><code><strong>输入：</strong></code><code>[[&quot;MUC&quot;, &quot;LHR&quot;], [&quot;JFK&quot;, &quot;MUC&quot;], [&quot;SFO&quot;, &quot;SJC&quot;], [&quot;LHR&quot;, &quot;SFO&quot;]]</code>
<strong>输出：</strong><code>[&quot;JFK&quot;, &quot;MUC&quot;, &quot;LHR&quot;, &quot;SFO&quot;, &quot;SJC&quot;]</code>
</pre>

<p><strong>示例 2：</strong></p>

<pre><code><strong>输入：</strong></code><code>[[&quot;JFK&quot;,&quot;SFO&quot;],[&quot;JFK&quot;,&quot;ATL&quot;],[&quot;SFO&quot;,&quot;ATL&quot;],[&quot;ATL&quot;,&quot;JFK&quot;],[&quot;ATL&quot;,&quot;SFO&quot;]]</code>
<strong>输出：</strong><code>[&quot;JFK&quot;,&quot;ATL&quot;,&quot;JFK&quot;,&quot;SFO&quot;,&quot;ATL&quot;,&quot;SFO&quot;]</code>
<strong>解释：</strong>另一种有效的行程是&nbsp;<code>[&quot;JFK&quot;,&quot;SFO&quot;,&quot;ATL&quot;,&quot;JFK&quot;,&quot;ATL&quot;,&quot;SFO&quot;]</code>。但是它自然排序更大更靠后。</pre>


## 相关话题

- [深度优先搜索](https://leetcode-cn.com/tag/depth-first-search)
- [图](https://leetcode-cn.com/tag/graph)

## 相似题目


