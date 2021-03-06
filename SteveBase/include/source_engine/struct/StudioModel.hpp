#pragma once

#include <maths/Vector3.hpp>

namespace SteveBase::SourceEngine::Structure {
    using namespace Maths;

    struct StudioModel {
        int					id;
        int					version;

        int					checksum;		// this has to be the same in the phy and vtx files to load!

        char				name[64];
        int					length;


        Vector3				eyeposition;	// ideal eye position

        Vector3				illumposition;	// illumination center

        Vector3				hull_min;		// ideal movement hull size
        Vector3				hull_max;

        Vector3				view_bbmin;		// clipping bounding box
        Vector3				view_bbmax;

        int					flags;

        int					numbones;			// bones
        int					boneindex;

        int					numbonecontrollers;		// bone controllers
        int					bonecontrollerindex;

        int					numhitboxsets;
        int					hitboxsetindex;

        // file local animations? and sequences
        //private:
        int					numlocalanim;			// animations/poses
        int					localanimindex;		// animation descriptions

        int					numlocalseq;				// sequences
        int					localseqindex;

        //private:
        mutable int			activitylistversion;	// initialization flag - have the sequences been indexed?
        mutable int			eventsindexed;

        // raw textures
        int					numtextures;
        int					textureindex;

        // raw textures search paths
        int					numcdtextures;
        int					cdtextureindex;

        // replaceable textures tables
        int					numskinref;
        int					numskinfamilies;
        int					skinindex;

        int					numbodyparts;
        int					bodypartindex;

        // queryable attachable points
        //private:
        int					numlocalattachments;
        int					localattachmentindex;

        int					numlocalnodes;
        int					localnodeindex;
        int					localnodenameindex;

        int					numflexdesc;
        int					flexdescindex;

        int					numflexcontrollers;
        int					flexcontrollerindex;

        int					numflexrules;
        int					flexruleindex;

        int					numikchains;
        int					ikchainindex;

        int					nummouths;
        int					mouthindex;

        //private:
        int					numlocalposeparameters;
        int					localposeparamindex;

        int					surfacepropindex;

        // Key values
        int					keyvalueindex;
        int					keyvaluesize;

        int					numlocalikautoplaylocks;
        int					localikautoplaylockindex;

        // The collision model mass that jay wanted
        float				mass;
        int					contents;

        // external animations, models, etc.
        int					numincludemodels;
        int					includemodelindex;

        // implementation specific back pointer to virtual data
        mutable void		*virtualModel;


        // for demand loaded animation blocks
        int					szanimblocknameindex;

        int					numanimblocks;
        int					animblockindex;

        mutable void		*animblockModel;


        int					bonetablebynameindex;

        // used by tools only that don't cache, but persist mdl's peer data
        // engine uses virtualModel to back link to cache pointers
        void				*pVertexBase;
        void				*pIndexBase;

        // if STUDIOHDR_FLAGS_CONSTANT_DIRECTIONAL_LIGHT_DOT is set,
        // this value is used to calculate directional components of lighting 
        // on static props
        char				constdirectionallightdot;

        // set during load of mdl data to track *desired* lod configuration (not actual)
        // the *actual* clamped root lod is found in studiohwdata
        // this is stored here as a global store to ensure the staged loading matches the rendering
        char				rootLOD;

        // set in the mdl data to specify that lod configuration should only allow first numAllowRootLODs
        // to be set as root LOD:
        //	numAllowedRootLODs = 0	means no restriction, any lod can be set as root lod.
        //	numAllowedRootLODs = N	means that lod0 - lod(N-1) can be set as root lod, but not lodN or lower.
        char				numAllowedRootLODs;

        char				unused[1];

        int					unused4; // zero out if version < 47

        int					numflexcontrollerui;
        int					flexcontrolleruiindex;

        float				flVertAnimFixedPointScale;

        int					unused3[1];

        // FIXME: Remove when we up the model version. Move all fields of studiohdr2_t into studiohdr_t.
        int					studiohdr2index;

        // NOTE: No room to add stuff? Up the .mdl file format version 
        // [and move all fields in studiohdr2_t into studiohdr_t and kill studiohdr2_t],
        // or add your stuff to studiohdr2_t. See NumSrcBoneTransforms/SrcBoneTransform for the pattern to use.
        int					unused2[1];
    };
}