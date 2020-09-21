
| English | [简体中文](README.md) |

# [577. Employee Bonus](https://leetcode-cn.com/problems/employee-bonus/)

## Description

<p>Select all employee&#39;s name and bonus whose bonus is &lt; 1000.</p>

<p>Table:<code>Employee </code></p>

<pre>
+-------+--------+-----------+--------+
| empId |  name  | supervisor| salary |
+-------+--------+-----------+--------+
|   1   | John   |  3        | 1000   |
|   2   | Dan    |  3        | 2000   |
|   3   | Brad   |  null     | 4000   |
|   4   | Thomas |  3        | 4000   |
+-------+--------+-----------+--------+
empId is the primary key column for this table.
</pre>

<p>Table: <code>Bonus</code></p>

<pre>
+-------+-------+
| empId | bonus |
+-------+-------+
| 2     | 500   |
| 4     | 2000  |
+-------+-------+
empId is the primary key column for this table.
</pre>

<p>Example ouput:</p>

<pre>
+-------+-------+
| name  | bonus |
+-------+-------+
| John  | null  |
| Dan   | 500   |
| Brad  | null  |
+-------+-------+
</pre>


## Related Topics



## Similar Questions

- [Combine Two Tables](../combine-two-tables/README_EN.md)
