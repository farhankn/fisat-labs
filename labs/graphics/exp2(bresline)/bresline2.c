#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
int xa,ya,xb,yb,dx,dy,x,y,p;


void display()
{
	
	
	glClearColor(0.5,1,0.5,1);
	glClear(GL_COLOR_BUFFER_BIT);
	glPointSize(2.0);
	dx=xb-xa;
	dy=yb-ya;
	p = 2 * dx - dy;

	x=xa;
	y=ya;
	printf("%d  %d\n",x,y);
	glBegin(GL_POINTS);
	glColor3f(1,0,0);
	glVertex2i(x,y);
	glEnd();
	 while(x < xb)
	      {
		    x = x + 1;
		    if(p < 0)
		    {
		         p = p + 2 * dx;
		    }
		    else
		    {
		          y = y + 1;
		          p = p + 2 * (dx - dy);
		    }
		   printf("%d  %d\n",x,y);
		   glBegin(GL_POINTS);
		   glColor3f(1,0,0);
		   glVertex2i(x,y);
		   glEnd();
	      }
			
	

	glFlush();
}

int main(int argc,char *argv[])
{
	
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE|GLUT_RGBA|GLUT_DEPTH);
	glutInitWindowSize(400,300);
	glutInitWindowPosition(500,100);
	glutCreateWindow("Bresenhams Line");
	glViewport(50,50,350,250);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0,300,0,300);
	printf("xa:\n");
	scanf("%d",&xa);
	printf("ya:\n");
	scanf("%d",&ya);
	printf("xb:\n");
	scanf("%d",&xb);
	printf("yb:\n");
	scanf("%d",&yb);
	glutDisplayFunc(display);
	
	glutMainLoop();
	return 0;
	
}
/* output
neg slope
00413@user:/mnt/00413/cg$ ./bresline2
xa:
0
ya:
200
xb:
200
yb:
100
0  200
1  201
2  202
3  203
4  204
5  205
6  206
7  207
8  208
9  209
10  210
11  211
12  212
13  213
14  214
15  215
16  216
17  217
18  218
19  219
20  220
21  221
22  222
23  223
24  224
25  225
26  226
27  227
28  228
29  229
30  230
31  231
32  232
33  233
34  234
35  235
36  236
37  237
38  238
39  239
40  240
41  241
42  242
43  243
44  244
45  245
46  246
47  247
48  248
49  249
50  250
51  251
52  252
53  253
54  254
55  255
56  256
57  257
58  258
59  259
60  260
61  261
62  262
63  263
64  264
65  265
66  266
67  267
68  268
69  269
70  270
71  271
72  272
73  273
74  274
75  275
76  276
77  277
78  278
79  279
80  280
81  281
82  282
83  283
84  284
85  285
86  286
87  287
88  288
89  289
90  290
91  291
92  292
93  293
94  294
95  295
96  296
97  297
98  298
99  299
100  300
101  301
102  302
103  303
104  304
105  305
106  306
107  307
108  308
109  309
110  310
111  311
112  312
113  313
114  314
115  315
116  316
117  317
118  318
119  319
120  320
121  321
122  322
123  323
124  324
125  325
126  326
127  327
128  328
129  329
130  330
131  331
132  332
133  333
134  334
135  335
136  336
137  337
138  338
139  339
140  340
141  341
142  342
143  343
144  344
145  345
146  346
147  347
148  348
149  349
150  350
151  351
152  352
153  353
154  354
155  355
156  356
157  357
158  358
159  359
160  360
161  361
162  362
163  363
164  364
165  365
166  366
167  367
168  368
169  369
170  370
171  371
172  372
173  373
174  374
175  375
176  376
177  377
178  378
179  379
180  380
181  381
182  382
183  383
184  384
185  385
186  386
187  387
188  388
189  389
190  390
191  391
192  392
193  393
194  394
195  395
196  396
197  397
198  398
199  399
200  400

*/
