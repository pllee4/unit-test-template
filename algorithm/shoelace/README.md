# Shoelace Algorithm

## Formula

$$\begin{equation*}
\begin{aligned}
\text { Area }&=\frac{1}{2}\left|\sum_{i=1}^{n-1} x_i y_{i+1}+x_n y_1-\sum_{i=1}^{n-1} x_{i+1} y_i-x_1 y_n\right| \\
&=\frac{1}{2}\left|x_A y_B+x_B y_C+x_C y_D+x_D y_E+x_E y_A-\left(y_A x_B+y_B x_C+y_C x_D+y_D x_E+y_E x_A\right)\right| \\
\end{aligned}
\end{equation*}$$


## References
1. https://www.101computing.net/the-shoelace-algorithm/#:~:text=The%20shoelace%20formula%20or%20shoelace,polygon%20to%20find%20its%20area.