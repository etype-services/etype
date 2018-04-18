/* add custom js */
(function ($) {
  "use strict";
  Drupal.behaviors.md_thenews = {
    attach: function (context, settings) {
      $("a[href$='e-edition']").attr('target', '_blank');
    };
})(jQuery);