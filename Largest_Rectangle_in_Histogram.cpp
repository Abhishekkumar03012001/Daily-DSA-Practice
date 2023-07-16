/*  #Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histogram.  */ 

class Solution {
private:
vector<int> nextSmallerElement(vector<int>& heights,int n)
{
stack<int>small;
small.push(-1);
vector<int>res(n);
for(int i=n-1;i>=0;i--)
{
    int curr=heights[i];
    while(small.top()!=-1 &&heights[small.top()] >= curr)
    {
        small.pop();
    }
    res[i]=small.top();
    small.push(i);
}
return res;
}

vector<int> prevSmallerElement(vector<int>& heights,int n)
{
stack<int>prev;
prev.push(-1);
vector<int>res(n);
for(int i=0;i<n;i++)
{
    int curr=heights[i];
    while(prev.top()!=-1 && heights[prev.top()] >= curr)
    {
        prev.pop();
    }
    res[i]=prev.top();
    prev.push(i);
}
return res;
}
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        vector<int>next(n);
        next=nextSmallerElement(heights,n);
        vector<int>prev(n);
        prev=prevSmallerElement(heights,n);
        int area=INT_MIN;
        for(int i=0;i<n;i++)
        {
            int l=heights[i];
            int b=next[i]-prev[i]-1;
            if(next[i]==-1)
            {
                next[i]=n;
            }
            b=next[i]-prev[i]-1;
            int area2=l*b;
            area=max(area,area2);
        }
        return area;
    }
};