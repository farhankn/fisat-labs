import numpy as np
import cv2
from matplotlib import pyplot as plt
img=cv2.imread('messi5.jpg',0) # 0 indicates Grayscale
rows,cols=img.shape
M = cv2.getRotationMatrix2D((cols/2,rows/2),90,1)





#cv2.imshow('Messi',img)
#k=cv2.waitKey(0)&0xFF #Accepting Keystroke
#if k==27:
#	cv2.destroyAllWindows()
#elif k==ord('s'):
#	cv2.imwrite('messigray.png',img)
#	print "Saved"
#print img
