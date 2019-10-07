/* add custom js */
(function ($) {
  'use strict';
  Drupal.behaviors.etype = {
    attach: function (context, settings) {
      $('a[href$="e-edition"]').attr('target', '_blank');

      var autocompleteOff = function () {
        if ($('#contact-site-form').length) {
          var field = 'autocomplete';
          var fill = 'nope';
          $('#contact-site-form').attr(field, 'off');
          $('#contact-site-form .form-item input[type="text"]').attr(field, fill);
          $('#contact-site-form .form-item textarea').attr(field, fill);
        }
      };
      autocompleteOff();
    }
  };
})(jQuery);


(function(s, o, g){
  a = s.createElement(o);
  m = s.getElementsByTagName(o)[0];
  a.src = g;
  a.setAttribute("async", "");
  a.setAttribute("type", "text/javascript");
  a.setAttribute("crossorigin", "anonymous");
  m.parentNode.insertBefore(a, m);
})(document, "script", "https://adatoolbar.com/wp-json/onlineada/v1/accessibility-toolbar/e687213560c8b");