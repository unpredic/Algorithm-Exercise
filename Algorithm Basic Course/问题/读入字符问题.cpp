    

// for (int i = 0; i < n; i ++ ) scanf("%s", g[i]); (推荐这种)
    
for (int i = 0; i < n; i ++ ) {
    for (int j = 0; j < n; j ++ ) {
    	// 这种方式有问题, 题：https://www.acwing.com/problem/content/description/1235/
        // scanf("%c", &g[i][j]);  
        cin >> g[i][j];
    }
}