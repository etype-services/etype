/* add custom js */
(function ($) {
    "use strict";
    Drupal.behaviors.etype = {
         attach: function (context, settings) {
            $('a[href$="e-edition"]').attr("target", "_blank");

            var autocompleteOff = function () {
              $("#contact-site-form").attr("autocomplete", "nope");
              $("#contact-site-form .form-item input").attr("autocomplete", "nope");
            };
            autocompleteOff();
        }
    };
})(jQuery);