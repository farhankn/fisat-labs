import numpy as np
import cv2
from matplotlib import pyplot as plt
img=cv2.imread('messi5.jpg',0) # 0 indicates Grayscale
plt.imshow(img, cmap = 'gray', interpolation = 'bicubic')
plt.xticks([]),plt.yticks([]) #to hide tick values on X and Y axis
plt.show()



#
#cv2.imshow('Messi',img)
#k=cv2.waitKey(0)&0xFF #Accepting Keystroke
#if k==27:
#	cv2.destroyAllWindows()
#elif k==ord('s'):
#	cv2.imwrite('messigray.png',img)
#	print "Saved"
#print img