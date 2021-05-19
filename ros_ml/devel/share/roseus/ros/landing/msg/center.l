;; Auto-generated. Do not edit!


(when (boundp 'landing::center)
  (if (not (find-package "LANDING"))
    (make-package "LANDING"))
  (shadow 'center (find-package "LANDING")))
(unless (find-package "LANDING::CENTER")
  (make-package "LANDING::CENTER"))

(in-package "ROS")
;;//! \htmlinclude center.msg.html


(defclass landing::center
  :super ros::object
  :slots (_width _height _x _y _iffind ))

(defmethod landing::center
  (:init
   (&key
    ((:width __width) 0)
    ((:height __height) 0)
    ((:x __x) 0.0)
    ((:y __y) 0.0)
    ((:iffind __iffind) nil)
    )
   (send-super :init)
   (setq _width (round __width))
   (setq _height (round __height))
   (setq _x (float __x))
   (setq _y (float __y))
   (setq _iffind __iffind)
   self)
  (:width
   (&optional __width)
   (if __width (setq _width __width)) _width)
  (:height
   (&optional __height)
   (if __height (setq _height __height)) _height)
  (:x
   (&optional __x)
   (if __x (setq _x __x)) _x)
  (:y
   (&optional __y)
   (if __y (setq _y __y)) _y)
  (:iffind
   (&optional __iffind)
   (if __iffind (setq _iffind __iffind)) _iffind)
  (:serialization-length
   ()
   (+
    ;; uint32 _width
    4
    ;; uint32 _height
    4
    ;; float64 _x
    8
    ;; float64 _y
    8
    ;; bool _iffind
    1
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; uint32 _width
       (write-long _width s)
     ;; uint32 _height
       (write-long _height s)
     ;; float64 _x
       (sys::poke _x (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; float64 _y
       (sys::poke _y (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;; bool _iffind
       (if _iffind (write-byte -1 s) (write-byte 0 s))
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; uint32 _width
     (setq _width (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; uint32 _height
     (setq _height (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float64 _x
     (setq _x (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; float64 _y
     (setq _y (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;; bool _iffind
     (setq _iffind (not (= 0 (sys::peek buf ptr- :char)))) (incf ptr- 1)
   ;;
   self)
  )

(setf (get landing::center :md5sum-) "435bfc8b0a9a23f7ba5ab3357a37f574")
(setf (get landing::center :datatype-) "landing/center")
(setf (get landing::center :definition-)
      "uint32 width
uint32 height
float64 x
float64 y
bool iffind

")



(provide :landing/center "435bfc8b0a9a23f7ba5ab3357a37f574")


