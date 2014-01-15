/*
 *  MaplyTexture_private.h
 *  WhirlyGlobe-MaplyComponent
 *
 *  Created by Steve Gifford on 10/25/13.
 *  Copyright 2011-2013 mousebird consulting
 *
 *  Licensed under the Apache License, Version 2.0 (the "License");
 *  you may not use this file except in compliance with the License.
 *  You may obtain a copy of the License at
 *  http://www.apache.org/licenses/LICENSE-2.0
 *
 *  Unless required by applicable law or agreed to in writing, software
 *  distributed under the License is distributed on an "AS IS" BASIS,
 *  WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 *  See the License for the specific language governing permissions and
 *  limitations under the License.
 *
 */

#import <Foundation/Foundation.h>
#import "MaplyTexture.h"
#import "MaplyBaseViewController.h"
#import "WhirlyGlobe.h"

@interface MaplyTexture()

// The view controller the texture is nominally associated with
@property (nonatomic,weak) MaplyBaseViewController *viewC;

// If set, the texture ID associated with this texture
@property (nonatomic) WhirlyKit::SimpleIdentity texID;

// Clear out the texture we're holding
- (void)clear;

@end

namespace WhirlyKit
{
    
// This wrapper class adds iOS specific functionality
class MaplyTextureWrapper : public Texture
{
public:
	/// Construct with a file name and extension
	MaplyTextureWrapper(const std::string &name,NSString *baseName,NSString *ext);
    // Construct with a UIImage.  Expecting this to be a power of 2 on each side.
    // If it's not we'll round up or down, depending on the flag
	MaplyTextureWrapper(const std::string &name,UIImage *inImage, bool roundUp=true);
    
protected:
    NSData *texNSData;
};
    
}