// Copyright(c) 2017 POLYGONTEK
// 
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// 
// http ://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

#pragma once

#include "ComCollider.h"

BE_NAMESPACE_BEGIN

class ComMeshCollider : public ComCollider {
public:
    OBJECT_PROTOTYPE(ComMeshCollider);

    ComMeshCollider();
    virtual ~ComMeshCollider();

    virtual void            Init() override;

    virtual void            SetEnable(bool enable) override;

    virtual bool            RayIntersection(const Vec3 &start, const Vec3 &dir, bool backFaceCull, float &lastScale) const override;

    virtual void            DrawGizmos(const SceneView::Parms &sceneView, bool selected) override;

    Guid                    GetMesh() const;
    void                    SetMesh(const Guid &meshGuid);

    ObjectRef               GetMeshRef() const;
    void                    SetMeshRef(const ObjectRef &meshRef);

protected:
    void                    PropertyChanged(const char *classname, const char *propName);

    Guid                    meshGuid;
    bool                    convex;
};

BE_NAMESPACE_END
