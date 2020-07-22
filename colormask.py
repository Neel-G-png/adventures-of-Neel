from cv2 import cv2
import numpy as np


clicked=False
hsv_frame=0
v=s=h=0
lower_bound=np.array([h,s,v])
upper_bound=np.array([h,s,v])
def draw_function(event, x,y,flags,param):
    if event == cv2.EVENT_LBUTTONDBLCLK:
        global h,s,v, clicked
        clicked = True
        h,s,v = hsv_frame[y,x]
        h = int(h)
        s = int(s)
        v = int(v)

cap=cv2.VideoCapture(0)
# ret,frame=cap.read()
# frame=cv2.flip(frame,1)
# cv2.imwrite("backg.jpg",frame)
backg=cv2.imread("backg.jpg")
backg=cv2.resize(backg,(1024,768),interpolation=cv2.INTER_LINEAR_EXACT)
while True:
    ret,frame=cap.read()
    frame=cv2.flip(frame,1)
    frame=cv2.resize(frame,(1024,768),interpolation=cv2.INTER_LINEAR_EXACT)
    cv2.namedWindow('magic')
    cv2.setMouseCallback('magic',draw_function)
    if (clicked):
        lower_bound=np.array([h-20,s-50,v-50])
        upper_bound=np.array([h+20,s+70,v+70])
        clicked=False
    blur=cv2.GaussianBlur(frame,(5,5),0)
    hsv_frame=cv2.cvtColor(blur,cv2.COLOR_BGR2HSV)
    # cv2.imshow("hsv_frame",hsv_image)
    mask=cv2.inRange(hsv_frame,lower_bound,upper_bound)
    #mask=cv2.morphologyEx(mask,cv2.MORPH_OPEN,(7,7))
    mask_inv=(255-mask)
    filtered=cv2.bitwise_and(backg,backg,mask=mask)
    magic=cv2.bitwise_or(frame,filtered,mask=mask_inv)
    final=magic+filtered
    # final=cv2.resize(final,(1024,768),interpolation=cv2.INTER_LINEAR_EXACT)
    #cv2.imshow("orignal",frame)
    cv2.imshow("magic",final)
    #cv2.imshow("mask",mask)
    #cv2.imshow("filter",filtered)
    if cv2.waitKey(1)==13:
        break
cap.release()
cv2.destroyAllWindows()