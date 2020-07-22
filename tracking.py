from cv2 import cv2
import numpy as np

cap=cv2.VideoCapture(0)
ret,frame=cap.read()
frame=cv2.flip(frame,1)
x,y,w,h=0,0,100,70
track_window=[x,y,w,h]
roi=frame[y:y+h,x:x+w]
hsv_roi=cv2.cvtColor(roi,cv2.COLOR_BGR2HSV)
lower_bound=np.array([15,100,100])
upper_bound=np.array([35,255,255])
pts=[]
#reg for recatangle X= 400 to 640 ,Y= 0 to 200
#pts [i][0]=x,pts[i][1]=y
while True:
    ret,frame=cap.read()
    frame=cv2.flip(frame,1)
    temp_frame=frame
    flag=0
    hsv_frame=cv2.cvtColor(frame,cv2.COLOR_BGR2HSV)
    mask=cv2.inRange(hsv_frame,lower_bound,upper_bound)
    roi_hist=cv2.calcHist([hsv_frame],[0],mask,[180],[0,180])
    roi_norm_hist=cv2.normalize(roi_hist,roi_hist,0,255,cv2.NORM_MINMAX)
    termination=(cv2.TERM_CRITERIA_EPS | cv2.TermCriteria_COUNT,40,10)
    dst=cv2.calcBackProject([hsv_frame],[0],roi_norm_hist,[0,180],1)
    ret,track_window=cv2.CamShift(dst,track_window,termination)
    x,y,w,h=track_window
    cv2.rectangle(frame,(x,y),(x+w,y+h),(0,255,0),2)
    center=int((2*x+w)/2),int((2*y+h)/2)
    pts.append(center)
    if center[0] in range(500,640) and center[1] in range(0,150):
        cv2.rectangle(temp_frame,(500,0),(640,150),(0,255,0),-1)
        cv2.putText(temp_frame,"ERASED",(510,70),cv2.FONT_HERSHEY_PLAIN,2,(255,0,0),2)
        temp_frame=cv2.resize(temp_frame,(1024,768),interpolation=cv2.INTER_LANCZOS4)
        cv2.imshow("tracking",temp_frame)
        flag=1
        pts=[]
    for i in range(1,len(pts)):
        x1=pts[i][0]
        y1=pts[i][1]
        if x1 not in range(500,640) or y1 not in range(0,150):
            cv2.line(frame,pts[i-1],pts[i],(255,0,255),2)
    if flag==0:
        frame=cv2.resize(frame,(1024,768),interpolation=cv2.INTER_LANCZOS4)
        cv2.imshow("tracking",frame)
    if cv2.waitKey(1)==13:
        break
cap.release()
cv2.destroyAllWindows()