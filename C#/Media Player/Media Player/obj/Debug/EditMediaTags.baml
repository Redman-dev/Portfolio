   M S B A M L   `   `   `  ����G  CMedia Player, Version=1.0.0.0, Culture=neutral, PublicKeyToken=null+clr-namespace:Media_PlayerMedia_Player  5           Media_Player.EditMediaTags   5      R NWindowsBase, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35W SPresentationCore, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35\ XPresentationFramework, Version=4.0.0.0, Culture=neutral, PublicKeyToken=31bf3856ad364e35D 9http://schemas.microsoft.com/winfx/2006/xaml/presentation    5      R NSystem.Xaml, Version=4.0.0.0, Culture=neutral, PublicKeyToken=b77a5c561934e089:x,http://schemas.microsoft.com/winfx/2006/xaml     5      Jmc;http://schemas.openxmlformats.org/markup-compatibility/2006     5      @d2http://schemas.microsoft.com/expression/blend/2008     5      ,localclr-namespace:Media_Player     5      .��5	      � -   5          �Name$  GForm��5	      ���	#7F000000 � ColumnDefinitions 5
      �� 5      $��50 �6   �� 5      $��* �6    � RowDefinitions 5   
   �� 5      ��6   �� *Height+ �� ElementName$ LTitle�� �� Mode$ OneWay=��� 5      ��6   �� *Height+$ LArtist��$ OneWay=��� 5      ��6   �� *Height+$ LAlbum��$ OneWay=��� 5      ��6   �� *Height+$ LYear��$ OneWay=��� 5      ��6   �� *Height+$ BSave��$ OneWay=�.+�5   
   �� -   5         ��Name$ LTitle��5      $��Title��6    $��0��61   $��0��6>   
�������$��Stretch=�6a   �� 5   
   -   5         ��Name$ TBTitle��5      $��0��6#   $��1��60   
�������$��Stretch=�6S    �� MaxLines$ 1��6q   ���	#00000000��6�   Z� �� 5   
   -   5        $ LArtist��5      $��Artist��6!   $��1��63   $��0��6@   
�������$��Stretch=�6c   �� 5   
   -   5        $ TBArtist��5      $��1��6$   $��1��61   
�������$��Stretch=�6T   $ 1��6r   ���	#00000000��6�   Z� �� 5   
   -   5        $ LAlbum��5      $��Album��6    $��2��61   $��0��6>   
�������$��Stretch=�6a   �� 5   
   -   5        $ TBAlbum��5      $��2��6#   $��1��60   
�������$��Stretch=�6T   $ 1��6r   ���	#00000000��6�   Z� �� 5   
   -   5        $ LYear��5      $
��Year��6   $��3��6/   $��0��6<   
�������$��Stretch=�6_   �� 5   
   -	   5        $ TBYear��5      $��3��6"   $��1��6/   
�������$��Stretch=�6R   $ 1��6p   ���	#00000000��6�   Z� �� 5   
   -
   5         ��Name$ BSave��5      $��4��6    $��2��6-   $
��Save��6A   $��Center=�6P   $	��Top=�6m   $��0,5,0,5q�6�   5      5      