import matplotlib.pyplot as plt
import numpy as np
import matplotlib.mlab as mlab
import math

def find_intersections(mu1, mu2, sigma1, sigma2):
	# Solution is quadratic, define a, b, c for
	# simplification
	a = 1.0/(2*sigma1**2) - 1.0/(2*sigma2**2)
	b = mu2/(sigma2**2) - mu1/(sigma1**2)
	c = (mu1**2)/(2*sigma1**2) - (mu2**2)/(2*sigma2**2) - np.log((sigma2)/(sigma1))
	sols = np.roots([a,b,c])
	soly1 = 1/(math.sqrt(2*math.pi)*sigma1)*np.exp((-(sols[0]-mu1)**2)/(2*(sigma1**2)))
	soly2 = 1/(math.sqrt(2*math.pi)*sigma1)*np.exp((-(sols[1]-mu1)**2)/(2*(sigma1**2)))
	return [[sols[0], soly1], [sols[1], soly2]]

def plot_two_gauss(mu1, mu2, sigma1, sigma2, intersections):
	x1 = np.linspace(mu1-4*(sigma1**2), mu1+4*(sigma1**2), 150)
	x2 = np.linspace(mu2-4*(sigma2**2), mu2+4*(sigma2**2), 150)
	plt.plot(x1, mlab.normpdf(x1, mu1, sigma1), x2, mlab.normpdf(x2, mu2, sigma2), intersections[0][0], intersections[0][1], 'rs', intersections[1][0], intersections[1][1], 'rs')
	plt.show()

