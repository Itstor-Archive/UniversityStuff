import cv2

lower = (30, 0, 0)
upper = (90, 255, 255)

background = cv2.imread('background.jpg')
foreground = cv2.VideoCapture('foreground.mp4')

background = cv2.resize(background, (640, 360))

while True:
    ret, frame = foreground.read()

    if ret:
        frame = cv2.resize(frame, (640, 360))
        hsv = cv2.cvtColor(frame, cv2.COLOR_BGR2HSV)

        mask = cv2.inRange(hsv, lower, upper)

        foreground_mask = cv2.bitwise_not(mask)
        frame_foreground = cv2.bitwise_and(frame, frame, mask=foreground_mask)
        frame_background = cv2.bitwise_and(background, background, mask=mask)

        combine = cv2.add(frame_background, frame_foreground)

        cv2.imshow('output', combine)

        if cv2.waitKey(1) & 0xFF == ord('q'):
            break
    else:
        foreground.set(cv2.CAP_PROP_POS_FRAMES, 0)
        continue

cv2.destroyAllWindows()
