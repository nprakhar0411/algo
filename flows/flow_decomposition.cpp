t e m p l a t e   < t y p e n a m e   T >  
 c l a s s   f l o w _ d e c o m p o s i t i o n   {  
     p u b l i c :  
     c o n s t   f l o w _ g r a p h < T >   & g ;  
  
     v e c t o r <   v e c t o r < i n t >   >   p a t h s ;  
     v e c t o r < T >   p a t h _ f l o w s ;  
     v e c t o r <   v e c t o r < i n t >   >   c y c l e s ;  
     v e c t o r < T >   c y c l e _ f l o w s ;  
  
     f l o w _ d e c o m p o s i t i o n ( c o n s t   f l o w _ g r a p h < T >   & _ g )   :   g ( _ g )   {  
     }  
  
     v o i d   d e c o m p o s e ( )   {  
         v e c t o r < T >   f s ( g . e d g e s . s i z e ( ) ) ;  
         f o r   ( i n t   i   =   0 ;   i   <   ( i n t )   g . e d g e s . s i z e ( ) ;   i + + )   {  
             f s [ i ]   =   g . e d g e s [ i ] . f ;  
         }  
         p a t h s . c l e a r ( ) ;  
         p a t h _ f l o w s . c l e a r ( ) ;  
         c y c l e s . c l e a r ( ) ;  
         c y c l e _ f l o w s . c l e a r ( ) ;  
         v e c t o r < i n t >   p t r ( g . n ) ;  
         f o r   ( i n t   i   =   0 ;   i   <   g . n ;   i + + )   {  
             p t r [ i ]   =   ( i n t )   g . g [ i ] . s i z e ( )   -   1 ;  
         }  
         v e c t o r < i n t >   w a s ( g . n ,   - 1 ) ;  
         i n t   s t a r t   =   g . s t ;  
         f o r   ( i n t   i t e r   =   0 ;   ;   i t e r + + )   {  
             b o o l   f o u n d _ s t a r t   =   f a l s e ;  
             w h i l e   ( t r u e )   {  
                 i f   ( p t r [ s t a r t ]   > =   0 )   {  
                     i n t   i d   =   g . g [ s t a r t ] [ p t r [ s t a r t ] ] ;  
                     i f   ( f s [ i d ]   >   g . e p s )   {  
                         f o u n d _ s t a r t   =   t r u e ;  
                         b r e a k ;  
                     }  
                     p t r [ s t a r t ] - - ;  
                     c o n t i n u e ;  
                 }  
                 s t a r t   =   ( s t a r t   +   1 )   %   g . n ;  
                 i f   ( s t a r t   = =   g . s t )   {  
                     b r e a k ;  
                 }  
             }  
             i f   ( ! f o u n d _ s t a r t )   {  
                 b r e a k ;  
             }  
             v e c t o r < i n t >   p a t h ;  
             b o o l   i s _ c y c l e   =   f a l s e ;  
             i n t   v   =   s t a r t ;  
             w h i l e   ( t r u e )   {  
                 i f   ( v   = =   g . f i n )   {  
                     b r e a k ;  
                 }  
                 i f   ( w a s [ v ]   = =   i t e r )   {  
                     b o o l   f o u n d   =   f a l s e ;  
                     f o r   ( i n t   i   =   0 ;   i   <   ( i n t )   p a t h . s i z e ( ) ;   i + + )   {  
                         i n t   i d   =   p a t h [ i ] ;  
                         a u t o   & e   =   g . e d g e s [ i d ] ;  
                         i f   ( e . f r o m   = =   v )   {  
                             p a t h . e r a s e ( p a t h . b e g i n ( ) ,   p a t h . b e g i n ( )   +   i ) ;  
                             f o u n d   =   t r u e ;  
                             b r e a k ;  
                         }  
                     }  
                     a s s e r t ( f o u n d ) ;  
                     i s _ c y c l e   =   t r u e ;  
                     b r e a k ;  
                 }  
                 w a s [ v ]   =   i t e r ;  
                 b o o l   f o u n d   =   f a l s e ;  
                 w h i l e   ( p t r [ v ]   > =   0 )   {  
                     i n t   i d   =   g . g [ v ] [ p t r [ v ] ] ;  
                     i f   ( f s [ i d ]   >   g . e p s )   {  
                         p a t h . p u s h _ b a c k ( i d ) ;  
                         v   =   g . e d g e s [ i d ] . t o ;  
                         f o u n d   =   t r u e ;  
                         b r e a k ;  
                     }  
                     p t r [ v ] - - ;  
                 }  
                 a s s e r t ( f o u n d ) ;  
             }  
             T   p a t h _ f l o w   =   n u m e r i c _ l i m i t s < T > : : m a x ( ) ;  
             f o r   ( i n t   i d   :   p a t h )   {  
                 p a t h _ f l o w   =   m i n ( p a t h _ f l o w ,   f s [ i d ] ) ;  
             }  
             f o r   ( i n t   i d   :   p a t h )   {  
                 f s [ i d ]   - =   p a t h _ f l o w ;  
                 f s [ i d   ^   1 ]   + =   p a t h _ f l o w ;  
             }  
             i f   ( i s _ c y c l e )   {  
                 c y c l e s . p u s h _ b a c k ( p a t h ) ;  
                 c y c l e _ f l o w s . p u s h _ b a c k ( p a t h _ f l o w ) ;  
             }   e l s e   {  
                 p a t h s . p u s h _ b a c k ( p a t h ) ;  
                 p a t h _ f l o w s . p u s h _ b a c k ( p a t h _ f l o w ) ;  
             }  
         }  
         f o r   ( c o n s t   T &   f   :   f s )   {  
             a s s e r t ( - g . e p s   < =   f   & &   f   < =   g . e p s ) ;  
         }  
     }  
 } ; 