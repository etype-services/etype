/* add custom js */
(function ($) {
    "use strict";
    Drupal.behaviors.etype = {
         attach: function (context, settings) {
            $('a[href$="e-edition"]').attr("target", "_blank");

            var autocompleteOff = function () {
                var field = "autocomplete";
                var fill = "nope";
                $("#contact-site-form").attr(field, "off");
                $('#contact-site-form .form-item input[type="text"]').attr(field, fill);
                $("#contact-site-form .form-item textarea").attr(field, fill);
            };
            autocompleteOff();
        }
    };
})(jQuery);