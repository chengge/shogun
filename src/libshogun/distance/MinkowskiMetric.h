/*
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * Written (W) 2006-2009 Christian Gehl
 * Copyright (C) 2006-2009 Fraunhofer Institute FIRST and Max-Planck-Society
 */

#ifndef _MINKOWSKIMETRIC_H___
#define _MINKOWSKIMETRIC_H___

#include "lib/common.h"
#include "distance/SimpleDistance.h"
#include "features/SimpleFeatures.h"

/** @brief class MinkowskiMetric 
 *
 * The Minkowski metric is one general class of metrics for a 
 * \f$\displaystyle R^{n}\f$ feature space also referred as 
 * the \f$\displaystyle L_{k} \f$ norm.
 *
 * \f[ \displaystyle
 *  d(\bf{x},\bf{x'}) = (\sum_{i=1}^{n} |\bf{x_{i}}-\bf{x'_{i}}|^{k})^{\frac{1}{k}}
 *  \quad x,x' \in R^{n}
 * \f]
 *
 * special cases:
 * -# \f$\displaystyle L_{1} \f$ norm: Manhattan distance @see CManhattanMetric
 * -# \f$\displaystyle L_{2} \f$ norm: Euclidean distance @see CEuclidianDistance
 *  
 * Note that the Minkowski distance tends to the Chebyshew distance for 
 * increasing \f$k\f$.
 *
 * @see <a href="http://en.wikipedia.org/wiki/Distance">Wikipedia: Distance</a>
 */
class CMinkowskiMetric: public CSimpleDistance<float64_t>
{
	public:
		/** constructor
		 *
		 * @param k parameter k
		 */
		CMinkowskiMetric(float64_t k);

		/** constructor
		 *
		 * @param l features of left-hand side
		 * @param r features of right-hand side
		 * @param k parameter k
		 */
		CMinkowskiMetric(CSimpleFeatures<float64_t>* l, CSimpleFeatures<float64_t>* r, float64_t k);
		virtual ~CMinkowskiMetric();

		/** constructor
		 *
		 * @param l features of left-hand side
		 * @param r features of right-hand side
		 */
		virtual bool init(CFeatures* l, CFeatures* r);

		/** cleanup distance */
		virtual void cleanup();

		/** load init data from file
		 *
		 * @param src file to load from
		 * @return if loading was successful
		 */
		virtual bool load_init(FILE* src);

		/** save init data to file
		 *
		 * @param dest file to save to
		 * @return if saving was successful
		 */
		virtual bool save_init(FILE* dest);

		/** get distance type we are
		 *
		 * @return distance type MINKOWSKI
		 */
		virtual EDistanceType get_distance_type() { return D_MINKOWSKI;}

		/** get name of the distance
		 *
		 * @return name Minkowski-Metric
		 */
		virtual const char* get_name() const { return "Minkowski-Metric"; }

	protected:
		/// compute distance for features a and b
		/// idx_{a,b} denote the index of the feature vectors
		/// in the corresponding feature object
		virtual float64_t compute(int32_t idx_a, int32_t idx_b);

	protected:
		/** parameter k */
		float64_t k;
};

#endif /* _MINKOWSKIMETRIC_H___ */
