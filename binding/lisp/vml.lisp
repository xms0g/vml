(ql:quickload "cffi")

(defpackage :vml
  (:use :common-lisp :cffi))

(in-package :vml)
(export '(
  vec-add 
  vec-sub 
  vec-mul 
  vec-div 
  vec-max 
  vec-min 
  vec-sadd 
  vec-ssub 
  vec-smul 
  vec-sdiv 
  vec-neg 
  vec-abs 
  vec-norm 
  vec-len 
  vec-dot))

(define-foreign-library libvml
  (t (:default "../../build/libvml")))

(use-foreign-library libvml)

(defcfun ("_vec_add" vec-add) :void
  (result (:pointer :float))
  (v1 (:pointer :float))
  (v2 (:pointer :float))
  (len :int))

(defcfun ("_vec_sub" vec-sub) :void
  (result (:pointer :float))
  (v1 (:pointer :float))
  (v2 (:pointer :float))
  (len :int))

(defcfun ("_vec_mul" vec-mul) :void
  (result (:pointer :float))
  (v1 (:pointer :float))
  (v2 (:pointer :float))
  (len :int))

(defcfun ("_vec_div" vec-div) :void
  (result (:pointer :float))
  (v1 (:pointer :float))
  (v2 (:pointer :float))
  (len :int))

(defcfun ("_vec_max" vec-max) :void
  (result (:pointer :float))
  (v1 (:pointer :float))
  (v2 (:pointer :float))
  (len :int))

(defcfun ("_vec_min" vec-min) :void
  (result (:pointer :float))
  (v1 (:pointer :float))
  (v2 (:pointer :float))
  (len :int))

(defcfun ("_vec_sadd" vec-sadd) :void 
  (result (:pointer :float))
  (v1 (:pointer :float))
  (scalar :int)
  (len :int))

(defcfun ("_vec_ssub" vec-ssub) :void
  (result (:pointer :float))
  (v1 (:pointer :float))
  (scalar :int)
  (len :int))

(defcfun ("_vec_smul" vec-smul) :void
  (result (:pointer :float))
  (v1 (:pointer :float))
  (scalar :int)
  (len :int))

(defcfun ("_vec_sdiv" vec-sdiv) :void
  (result (:pointer :float))
  (v1 (:pointer :float))
  (scalar :int)
  (len :int))

(defcfun ("_vec_neg" vec-neg) :void 
  (result (:pointer :float))
  (v1 (:pointer :float))
  (len :int))

(defcfun ("_vec_abs" vec-abs) :void 
  (result (:pointer :float))
  (v1 (:pointer :float))
  (len :int))

(defcfun ("_vec_norm" vec-norm) :void
  (result (:pointer :float)) 
  (v1 (:pointer :float))
  (len :int))

(defcfun ("_vec_len" vec-len) :float 
  (v1 (:pointer :float)) 
  (len :int))

(defcfun ("_vec_dot" vec-dot) :float 
  (v1 (:pointer :float)) 
  (v2 (:pointer :float)) 
  (len :int))
