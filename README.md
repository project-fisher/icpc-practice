# icpc-practice
Practice problems for icpc solved in C++11.
Most of the problems are the ones that are starred in the book **Competitive programming 3**.

## UHUNT page
https://uhunt.onlinejudge.org/id/1274690

## General tips collected over time
<ol>
<li>Don't mix printf/scanf with cout/cin.</li>
<li>Use fast input with:
<pre><code>
ios\_base::sync\_with\_stdio(0);
cin.tie(0);
</code></pre>
</li>
<li>Include all std libraries, might as well.
<pre><code>
#include &lt;bits/stdc++.h&gt;

using namespace std;
</code></pre>
</li>
<li>Use the <code>auto</code> keyword for loops and some declarations.</li>
<li>Cin/cout is better for generic or very specific io. On the other hand, it's better to use scanf/printf for cases with specific yet common io.</li>
<li>Avoid branching (ifs, whiles, etc). Useful page: <a href="http://www.graphics.stanford.edu/~seander/bithacks.html">Bit Twiddling Hacks</a>.</li>
<li>Use <code>sort(vec.begin(), vec.end())</code>. Avoid writing your own sorts.</li>
<li>Use <code>vec.emplace\_back(element)</code>. Faster...</li>
<li>Use bitshifting when possible.</li>
<li>Iteration > recursion.</li>
<li>Use 1 dimensional arrays over multidimnesional.</li>
<li>Use <code>bitset\<size\></code> for big mitmasks.</li>
</ol>
