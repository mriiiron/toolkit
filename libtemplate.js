(function (window) {
    'use strict'

    function Single() {}


    function Multiple() {

        function Foo() {}

        function Bar() {}

        return {
            Foo: Foo,
            Bar: Bar
        };

    }


    if (typeof(window.single) === 'undefined'){
        window.single = Single;
    }

    if (typeof(window.multiple) === 'undefined'){
        window.multiple = Multiple();
    }

})(window);
