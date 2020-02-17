import numpy as np
from matplotlib import pyplot as plt


def plot_save(x, y, x_label, y_label):
	plt.plot(x, y, '.', label='Real Data Point')	
	plt.xlabel(x_label)
	plt.ylabel(y_label)
	if y_label == 'SORT_TIME_MS':
		quad_fn = np.poly1d(np.polyfit(x, y, deg=2))
		_x = np.linspace(0, 100000, 100000)
		_y = quad_fn(_x)
		plt.plot(_x, _y, 'r-', label='Best Fit Least Square Quadratic')
	plt.legend(loc='upper left')
	plt.savefig(x_label+' vs '+y_label+'.png')
	plt.close()


def main():
	with open('logs.txt') as f:
		data_with_header = f.readlines()
		headers = data_with_header[0].split(',')
		data = data_with_header[1:]
		for i in range(len(data)):
			data[i] = [eval(x) for x in data[i].split(',')]
		data_dict = {}
		for i in range(len(headers)):
			data_dict[headers[i]] = np.array([dat[i] for dat in data])
		for i in range(1, len(headers)):
			plot_save(data_dict['N'], data_dict[headers[i]], 'N', headers[i])
	pass


if __name__ == '__main__':
	main()
