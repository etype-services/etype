/* add custom js */
(function ($) {
    "use strict";
    Drupal.behaviors.etype = {
         attach: function (context, settings) {
            $('a[href$="e-edition"]').attr("target", "_blank");
        }
    };
})(jQuery);