;; Auto-generated. Do not edit!


(when (boundp 'learning_topic::Person)
  (if (not (find-package "LEARNING_TOPIC"))
    (make-package "LEARNING_TOPIC"))
  (shadow 'Person (find-package "LEARNING_TOPIC")))
(unless (find-package "LEARNING_TOPIC::PERSON")
  (make-package "LEARNING_TOPIC::PERSON"))

(in-package "ROS")
;;//! \htmlinclude Person.msg.html


(defclass learning_topic::Person
  :super ros::object
  :slots (_name _age _height ))

(defmethod learning_topic::Person
  (:init
   (&key
    ((:name __name) "")
    ((:age __age) 0)
    ((:height __height) 0.0)
    )
   (send-super :init)
   (setq _name (string __name))
   (setq _age (round __age))
   (setq _height (float __height))
   self)
  (:name
   (&optional __name)
   (if __name (setq _name __name)) _name)
  (:age
   (&optional __age)
   (if __age (setq _age __age)) _age)
  (:height
   (&optional __height)
   (if __height (setq _height __height)) _height)
  (:serialization-length
   ()
   (+
    ;; string _name
    4 (length _name)
    ;; uint32 _age
    4
    ;; float64 _height
    8
    ))
  (:serialize
   (&optional strm)
   (let ((s (if strm strm
              (make-string-output-stream (send self :serialization-length)))))
     ;; string _name
       (write-long (length _name) s) (princ _name s)
     ;; uint32 _age
       (write-long _age s)
     ;; float64 _height
       (sys::poke _height (send s :buffer) (send s :count) :double) (incf (stream-count s) 8)
     ;;
     (if (null strm) (get-output-stream-string s))))
  (:deserialize
   (buf &optional (ptr- 0))
   ;; string _name
     (let (n) (setq n (sys::peek buf ptr- :integer)) (incf ptr- 4) (setq _name (subseq buf ptr- (+ ptr- n))) (incf ptr- n))
   ;; uint32 _age
     (setq _age (sys::peek buf ptr- :integer)) (incf ptr- 4)
   ;; float64 _height
     (setq _height (sys::peek buf ptr- :double)) (incf ptr- 8)
   ;;
   self)
  )

(setf (get learning_topic::Person :md5sum-) "edecbfe8e59cb383a201db817e5000fb")
(setf (get learning_topic::Person :datatype-) "learning_topic/Person")
(setf (get learning_topic::Person :definition-)
      "string name
uint32 age
float64 height

")



(provide :learning_topic/Person "edecbfe8e59cb383a201db817e5000fb")


