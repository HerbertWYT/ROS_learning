; Auto-generated. Do not edit!


(cl:in-package landing-msg)


;//! \htmlinclude center.msg.html

(cl:defclass <center> (roslisp-msg-protocol:ros-message)
  ((width
    :reader width
    :initarg :width
    :type cl:integer
    :initform 0)
   (height
    :reader height
    :initarg :height
    :type cl:integer
    :initform 0)
   (x
    :reader x
    :initarg :x
    :type cl:float
    :initform 0.0)
   (y
    :reader y
    :initarg :y
    :type cl:float
    :initform 0.0)
   (iffind
    :reader iffind
    :initarg :iffind
    :type cl:boolean
    :initform cl:nil))
)

(cl:defclass center (<center>)
  ())

(cl:defmethod cl:initialize-instance :after ((m <center>) cl:&rest args)
  (cl:declare (cl:ignorable args))
  (cl:unless (cl:typep m 'center)
    (roslisp-msg-protocol:msg-deprecation-warning "using old message class name landing-msg:<center> is deprecated: use landing-msg:center instead.")))

(cl:ensure-generic-function 'width-val :lambda-list '(m))
(cl:defmethod width-val ((m <center>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader landing-msg:width-val is deprecated.  Use landing-msg:width instead.")
  (width m))

(cl:ensure-generic-function 'height-val :lambda-list '(m))
(cl:defmethod height-val ((m <center>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader landing-msg:height-val is deprecated.  Use landing-msg:height instead.")
  (height m))

(cl:ensure-generic-function 'x-val :lambda-list '(m))
(cl:defmethod x-val ((m <center>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader landing-msg:x-val is deprecated.  Use landing-msg:x instead.")
  (x m))

(cl:ensure-generic-function 'y-val :lambda-list '(m))
(cl:defmethod y-val ((m <center>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader landing-msg:y-val is deprecated.  Use landing-msg:y instead.")
  (y m))

(cl:ensure-generic-function 'iffind-val :lambda-list '(m))
(cl:defmethod iffind-val ((m <center>))
  (roslisp-msg-protocol:msg-deprecation-warning "Using old-style slot reader landing-msg:iffind-val is deprecated.  Use landing-msg:iffind instead.")
  (iffind m))
(cl:defmethod roslisp-msg-protocol:serialize ((msg <center>) ostream)
  "Serializes a message object of type '<center>"
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'width)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'width)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'width)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'width)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'height)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'height)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'height)) ostream)
  (cl:write-byte (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'height)) ostream)
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'x))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:let ((bits (roslisp-utils:encode-double-float-bits (cl:slot-value msg 'y))))
    (cl:write-byte (cl:ldb (cl:byte 8 0) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 8) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 16) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 24) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 32) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 40) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 48) bits) ostream)
    (cl:write-byte (cl:ldb (cl:byte 8 56) bits) ostream))
  (cl:write-byte (cl:ldb (cl:byte 8 0) (cl:if (cl:slot-value msg 'iffind) 1 0)) ostream)
)
(cl:defmethod roslisp-msg-protocol:deserialize ((msg <center>) istream)
  "Deserializes a message object of type '<center>"
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'width)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'width)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'width)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'width)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 0) (cl:slot-value msg 'height)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 8) (cl:slot-value msg 'height)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 16) (cl:slot-value msg 'height)) (cl:read-byte istream))
    (cl:setf (cl:ldb (cl:byte 8 24) (cl:slot-value msg 'height)) (cl:read-byte istream))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'x) (roslisp-utils:decode-double-float-bits bits)))
    (cl:let ((bits 0))
      (cl:setf (cl:ldb (cl:byte 8 0) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 8) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 16) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 24) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 32) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 40) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 48) bits) (cl:read-byte istream))
      (cl:setf (cl:ldb (cl:byte 8 56) bits) (cl:read-byte istream))
    (cl:setf (cl:slot-value msg 'y) (roslisp-utils:decode-double-float-bits bits)))
    (cl:setf (cl:slot-value msg 'iffind) (cl:not (cl:zerop (cl:read-byte istream))))
  msg
)
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql '<center>)))
  "Returns string type for a message object of type '<center>"
  "landing/center")
(cl:defmethod roslisp-msg-protocol:ros-datatype ((msg (cl:eql 'center)))
  "Returns string type for a message object of type 'center"
  "landing/center")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql '<center>)))
  "Returns md5sum for a message object of type '<center>"
  "435bfc8b0a9a23f7ba5ab3357a37f574")
(cl:defmethod roslisp-msg-protocol:md5sum ((type (cl:eql 'center)))
  "Returns md5sum for a message object of type 'center"
  "435bfc8b0a9a23f7ba5ab3357a37f574")
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql '<center>)))
  "Returns full string definition for message of type '<center>"
  (cl:format cl:nil "uint32 width~%uint32 height~%float64 x~%float64 y~%bool iffind~%~%~%"))
(cl:defmethod roslisp-msg-protocol:message-definition ((type (cl:eql 'center)))
  "Returns full string definition for message of type 'center"
  (cl:format cl:nil "uint32 width~%uint32 height~%float64 x~%float64 y~%bool iffind~%~%~%"))
(cl:defmethod roslisp-msg-protocol:serialization-length ((msg <center>))
  (cl:+ 0
     4
     4
     8
     8
     1
))
(cl:defmethod roslisp-msg-protocol:ros-message-to-list ((msg <center>))
  "Converts a ROS message object to a list"
  (cl:list 'center
    (cl:cons ':width (width msg))
    (cl:cons ':height (height msg))
    (cl:cons ':x (x msg))
    (cl:cons ':y (y msg))
    (cl:cons ':iffind (iffind msg))
))
