/***************************************************************************/
/*                                                                         */
/*  ftsnames.h                                                             */
/*                                                                         */
/*    Simple interface to access SFNT name tables (which are used          */
/*    to hold font names, copyright info, notices, etc.) (specification).  */
/*                                                                         */
/*    This is _not_ used to retrieve glyph names!                          */
/*                                                                         */
/*  Copyright 1996-2003, 2006, 2009, 2010, 2013 by                         */
/*  David Turner, Robert Wilhelm, and Werner Lemberg.                      */
/*                                                                         */
/*  This file is part of the FreeType project, and may only be used,       */
/*  modified, and distributed under the terms of the FreeType project      */
/*  license, LICENSE.TXT.  By continuing to use, modify, or distribute     */
/*  this file you indicate that you have read the license and              */
/*  understand and accept it fully.                                        */
/*                                                                         */
/***************************************************************************/


#ifndef __FT_SFNT_NAMES_H__
#define __FT_SFNT_NAMES_H__


#include <ft2build.h>
#include FT_FREETYPE_H

#ifdef FREETYPE_H
#error "freetype.h of FreeType 1 has been loaded!"
#error "Please fix the directory search order for header files"
#error "so that freetype.h of FreeType 2 is found first."
#endif


FT_BEGIN_HEADER


  /*************************************************************************/
  /*                                                                       */
  /* <Section>                                                             */
  /*    sfnt_names                                                         */
  /*                                                                       */
  /* <Title>                                                               */
  /*    SFNT Names                                                         */
  /*                                                                       */
  /* <Abstract>                                                            */
  /*    Access the names embedded in TrueType and OpenType files.          */
  /*                                                                       */
  /* <Description>                                                         */
  /*    The TrueType and OpenType specifications allow the inclusion of    */
  /*    a special `names table' in font files.  This table contains        */
  /*    textual (and internationalized) information regarding the font,    */
  /*    like family name, copyright, version, etc.                         */
  /*                                                                       */
  /*    The definitions below are used to access them if available.        */
  /*                                                                       */
  /*    Note that this has nothing to do with glyph names!                 */
  /*                                                                       */
  /*************************************************************************/


  /*************************************************************************/
  /*                                                                       */
  /* <Struct>                                                              */
  /*    FT_SfntName                                                        */
  /*                                                                       */
  /* <Description>                                                         */
  /*    A structure used to model an SFNT `name' table entry.              */
  /*                                                                       */
  /* <Fields>                                                              */
  /*    platform_id :: The platform ID for `string'.                       */
  /*                                                                       */
  /*    encoding_id :: The encoding ID for `string'.                       */
  /*                                                                       */
  /*    language_id :: The language ID for `string'.                       */
  /*                                                                       */
  /*    name_id     :: An identifier for `string'.                         */
  /*                                                                       */
  /*    string      :: The `name' string.  Note that its format differs    */
  /*                   depending on the (platform,encoding) pair.  It can  */
  /*                   be a Pascal String, a UTF-16 one, etc.              */
  /*                                                                       */
  /*                   Generally speaking, the string is not               */
  /*                   zero-terminated.  Please refer to the TrueType      */
  /*                   specification for details.                          */
  /*                                                                       */
  /*    string_len  :: The length of `string' in bytes.                    */
  /*                                                                       */
  /* <Note>                                                                */
  /*    Possible values for `platform_id', `encoding_id', `language_id',   */
  /*    and `name_id' are given in the file `ttnameid.h'.  For details     */
  /*    please refer to the TrueType or OpenType specification.            */
  /*                                                                       */
  /*    See also @TT_PLATFORM_XXX, @TT_APPLE_ID_XXX, @TT_MAC_ID_XXX,       */
  /*    @TT_ISO_ID_XXX, and @TT_MS_ID_XXX.                                 */
  /*                                                                       */
  typedef struct  FT_SfntName_
  {
    FT_UShort  platform_id;
    FT_UShort  encoding_id;
    FT_UShort  language_id;
    FT_UShort  name_id;

    FT_Byte*   string;      /* this string is *not* null-terminated! */
    FT_UInt    string_len;  /* in bytes */

  } FT_SfntName;


  /*************************************************************************/
  /*                                                                       */
  /* <Function>                                                            */
  /*    FT_Get_Sfnt_Name_Count                                             */
  /*                                                                       */
  /* <Description>                                                         */
  /*    Retrieve the number of name strings in the SFNT `name' table.      */
  /*                                                                       */
  /* <Input>                                                               */
  /*    face :: A handle to the source face.                               */
  /*                                                                       */
  /* <Return>                                                              */
  /*    The number of strings in the `name' table.                         */
  /*                                                                       */
  FT_EXPORT( FT_UInt )
  FT_Get_Sfnt_Name_Count( FT_Face  face );


  /*************************************************************************/
  /*                                                                       */
  /* <Function>                                                            */
  /*    FT_Get_Sfnt_Name                                                   */
  /*                                                                       */
  /* <Description>                                                         */
  /*    Retrieve a string of th�yk�P�3
�f�g� I���=QSj\�]����&@� ��*�ڛ���O�(��u��v��(o�ή>�c&�!�vW�_��٢�4��@l�_��x�u�/��҆R���sn�$h���+t*!�H�	�X�IT�p����q�G��r�<�;p� /��@Gj�#��X
A\fF�o�0�`��������Y���LB����D^0�yi):F՜��k\"�
Ns��djƃ!����Z-Ȯ�d`s^h1x�+�TM^��}�E�V}0��(h��Y# ۧ��X�YF��; :�+je��	d�{b�M�[�*b��.F�L<ClzA�Js&���T6�_��u��C�]_2T��W�O־��=*��ʕ����S*�#'٨(F���0���l1�ć��t�L���9�@�w'z���:��? �q����`�<}p1�&�y����8}eO��Pjm�S���6�b�I+5s�l�����z�]+�
}LgD�b@Fv��nm�5>w�d$���^v��qPZ��h�O�1������.0)��$Cb���a��U��
w��l1�%iq(�3N�L��fd���l�헧I-��̟����}��Y}�d�&/"����j���G�B�0U`���u�ͭ4pchW �lb�xL*���Mk�Wf������l��
���&u�;�~�9�[Wo�U��!����`j�Y,�����i�[w%t�ȴ>�"t㧠ɤ�i�0�����sv3�I�lDR ��15!�g��<��;��X}�[��HL���}*o�2��<�Z|���D����?�#[�O>�@�!��dȀ�)	:���W�p��R����%���I!W�`��,WZ���equ�K�)Ty� ��X��%�4��(bfӹF|��϶���D4:��P��P23�?h��2�k���~�����6�FP���|۪�Z�k�ϯ�x�ݵU6Ռ��Cf�9MӬ�ûf��Q�9��R(kl�s��J�y|\J�F��g3���&�]��4v��YP>C����a��.U�H�a�����3��})�_IXsB��4Y�3����1�Å�?���/,�|V"������̹�T�n�S���4wH�����/���?�Kh��j�C���}�Y��L.�_�*� �kz�Hƫm��D�|���b�E�	�kl4�Q6zu�!?�����  ���&�U��iW&<@Hf����}��y��������׸}�����#���\vӓ�H	��Q�E���˺-���E����6㨙����,P���:��:h��5^���x����^>5Zcq�,�v�k�#(���c�%�uZ�i�Oe񿠠[���)ṓ�9��Q,śr���J/S��V篦"c�ʧ�=�N�-�tN w�잣PT���b�ȸ�2��b`�	�7��;W�}6Hkm8��,��G�v�b1s�[ ��<���N�F��.̰_�v�K����v~���WZ���6�A����sm �Hs��>`i��3:3*��4��f��q���:��`�vo�b(k�߶դ�Z��Z�Pk���O��+\�y  r'A���ԙL�k�O�|�8AK���l~�z������ 75�))('�C��;w��d�p����k��z`+��-]��eʕ�T~�����8#PE��@D�qڠP�s���
ݾ�V�K�f�����c%q�T=lKu�3�䷨5=�xaڱ2ZS��$��L�^pi�"���ϧ#�-ju��Z�h[�k�.��l�[�!�x9�BY�r�3������ ��];,i:��E�<�1O֠�bC�w�Ё�y6�mG�Y}T_��8j��cp+� 6�6�IUjCi������3�Nj�4D%�TA�ʯ�^V��1%���#���P��N�%��ʰ.��f�� 2���oX(��f,S$�S{(�%���������`e!;�(��{W������./�L�+��Nh�]o*��ʯ�d�l����J��"}�z��}���و#e��s}�	O��x����@ӆ��E�SC�����ZG�a���~R�)3ޛ;^�W��u���ɣ�"f�7�P�h
L���
�ZRk7����t�bQ(�s�_���@x�,fp�p\��J�7�7�=���5z�ƤF�SW:)�k�����U��b4�=Ӈ'_@� Q����r,�țN�Tڈ R��n֟|��f��s��w����1}۞jԪ������*DU}�G��`Ⱁ�L�'(��D2L��C�=J���>�9n�6�Z\6e��]/DI������qEaj�䀋���S����=���}6� �味���$�4cb��K1�T�A��:�3'0���K1��w�ߔ6\�T>�ޠ��*��/���	�TtP+���r%��j�0Q�+WV���3�ؗŬ�
��35��A�d��/�-�Ж��bF��&�!J'�����%G���6}���`'��)�	�,Q� W@}>wD^�]<��P�#��a� �h�8�Yv=�&7M@����Z�6�g��l���%����UtT'G� �nWc����ވ�]!*�u�q��z�]:�J�È�燹=iED���i9K2�d�Z��=������������;��p��Y�<��M�i��BU؊h������C�T�Z���e�K?4+6�l���� ���姜��=�[��ؖ�@,
vY��B�fI�ԽƇ���@�o���f�{����^�s��(��X�l�l��o]�/2+�{PR��R{v�E<�����Q�I2w���� T����.;�fg��tb�D�k(E
)$����n2��|R�
��R}��@1I��������l$-��mK��%�s��zէz�Ik������7�k@B<�9;*=�Y��G��e�)3�t�uK��T}�C� W���|ීC�:��\��]rS^zG�1���2