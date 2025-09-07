(defsystem "cl-vml"
  :name "cl-vml"
  :version "0.0.1"
  :author "M. Sami Gürpınar <sami.gurpinar@gmail.com>"
  :description "Lisp bindings for vml"
  :license "LGPL-3.0-or-later"
  :depends-on (:cffi
               :quicklisp)
  :components ((:file "vml"))
  :in-order-to ((test-op (test-op vml-test))))
