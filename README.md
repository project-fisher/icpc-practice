# icpc-practice
Practice problems for icpc solved in C++11.
Most of the problems are the ones that are starred in the book **Competitive programming 3**.

## UHUNT page
https://uhunt.onlinejudge.org/id/1274690

## General tips collected over time
<ol>
<li>printf/scanf are generally faster than cout/cin.</li>
<li>If you're gonna use cout/cin anyways, include the following piece of code at the very beggining of your main function: <code>ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);</code></li>
<li>Iteration > recursion.</li>
<li>If it's already implemented, use it. That is to say, know your standard libraries. In any case, ICPC generally lets you have access to the language manual of your choice.</li>
<li>Learn bit tricks: <a href="http://www.graphics.stanford.edu/~seander/bithacks.html">Bit Twiddling Hacks</a>.</li>
<li>Know when to be careful with imports and when to be careless. It's better to import all of them using a single line during a competition than writing out the 10 you will actually use. P.S. use defines when a certain type gets repreated a lot.</li>
<pre><code>#include &lt;bits/stdc++.h&gt;
using namespace std;</code></pre>
<li>Have external algorithms/data structures on hand.</li>
</ol>
