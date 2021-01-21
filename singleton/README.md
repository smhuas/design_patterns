why singleton Pattern ?
    This design pattern make sure user creates only one instance/object of the class.
examples of singleton
    1) suppose in your application ur using a logger, and make sure user use only one single instance of logger, use singleton.

    what is needed to build singleton:-
    --> static function to getinstance
    --> static variable to store instance
    --> keep default ctor in private
    --> delete copy, assignment ctors